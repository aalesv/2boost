#This file is part of 2Boost
#
#2Boost is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
#
#This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#
#Prepares XML definitions using a definitions template.
#Input data must be readelf output.
#
#Example of readelf output
#===Start of output===
#
#Symbol table '.symtab' contains 464 entries:
#   Num:    Value  Size Type    Bind   Vis      Ndx Name
#     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND
#     1: 0008f000     0 SECTION LOCAL  DEFAULT    1
#===End of output===
#
#Note it has an empty line at the beginning, line with a description
#and line with column headers. These must be skipped before
#writing to a file (if '-i' parameter is specified).
#These lines are skipped automaticaly when reading from stdin

import argparse
from lxml import etree as ET
import csv, sys, os, errno
import re

#Sanitize XML tag text with regex and remove 'sanitizer' attribute.
#If tag has 'sanitizer' attribute, its value will be preferred over default_sanitizer
def sanitize_tag_text(tag, text, default_sanitizer=None):
    sanitizer_attrib_name = 'sanitizer'
    #Get attribute value
    s = tag.get(sanitizer_attrib_name)
    sanitizer = default_sanitizer if s is None else s
    text_new = text
    if sanitizer is not None:
        #Search the whole string, return only matched part
        text_new = re.search(sanitizer, text).group()
    tag.text = text_new
    #Remove attribute
    try:
        tag.attrib.pop(sanitizer_attrib_name)
    except KeyError:
        pass

#Argument parser object
parser = argparse.ArgumentParser(
    formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    description='Prepare XML definitions using a definitions template. Input data must be \'readelf --wide -s <binary_file>\' output.',
    epilog='Resulting file is not a valid definitions file. Please examine it and correct it!'
)
#Command line parameter for a file that contains a table output by readelf
#If not specified stdin is used
parserGroupOptions = parser.add_argument(
    '-i', '--input',
    metavar='<filename>',
    help='Input file name. STDIN if not specified.'
)
#Command line parameter for a RomRaider definitions XML template file
#Required.
parserGroupOtpions = parser.add_argument(
    '-t', '--template',
    metavar='<filename>',
    required=True,
    help='Template file name.'
)
#Command line parameter for a file that contains processed RomRaider XML definitions file
#If not specified stdout is used
parserGroupOptions = parser.add_argument(
    '-o', '--output',
    metavar='<filename>',
    help='Output file name. STDOUT if not specified.'
)

#String for a 'base' attribute of 'xml' tag, e.g.
#<xml base="2Boost CALID">
parserGroupOptions = parser.add_argument(
    '--rombase',
    metavar='<string>',
    help='String for a \'base\' attribute of \'rom\' tag. Leave it intact if not specified.'
)

#String for a 'internalidstring' XML tag
parserGroupOptions = parser.add_argument(
    '--internalidstring',
    metavar='<string>',
    help='Internal ID string. Will be written to \'internalidstring\' tag. Will be written to \'xmlid\' tag too. Leave them intact if not specified.'
)

#Parse command line options
#Check for required parameters, throws error if needed,
#outputs help and version messages
args = parser.parse_args()

#Get input and output file names
#None if not specified
input_file_name = args.input
output_file_name = args.output
#Get XML template file name
xml_template_file_name = args.template
#Internal ID and XML ID string
internal_id_string = args.internalidstring
#'base' attribute of 'rom' tag
rom_base = args.rombase

#Raise an error if template XML file does not exists
if not os.path.isfile(xml_template_file_name):
    raise FileNotFoundError(errno.ENOENT, os.strerror(errno.ENOENT), xml_template_file_name)

#Set stdin/stdout flags if needed
INPUT_FROM_STDIN = input_file_name is None
OUTPUT_TO_STDOUT = output_file_name is None

#Set file names
input_file = sys.stdin if INPUT_FROM_STDIN else input_file_name
output_file = sys.stdout if OUTPUT_TO_STDOUT else output_file_name

#If reading from stdin, skip first lines
#See notes about readelf output format above
if INPUT_FROM_STDIN:
    next(sys.stdin)
    next(sys.stdin)
    next(sys.stdin)

#Read input as CSV and convert to a list
rows = csv.reader(input_file, skipinitialspace=True, delimiter=' ')

#Read XML template
xml_parser = ET.XMLParser(target=ET.TreeBuilder(insert_comments=True))
#And parse it
xml_root = ET.parse(xml_template_file_name, xml_parser)

#Set 'base' attribute of 'rom' tag
if rom_base is not None:
    for rom in xml_root.xpath('/rom'):
        rom.set('base', rom_base)

#Set ID strings
if internal_id_string is not None:
    sanitize_tag_text(xml_root.find('.//xmlid'), internal_id_string)
    sanitize_tag_text(xml_root.find('.//internalidstring'), internal_id_string)

#Process every row in list
for row in rows:
    address = row[1]
    #Float consumes 4 bytes
    #Actually needed only for axis
    size = int(int(row[2]) / 4)
    #Convert number to string because attribute values must be string literals
    size_str = str(size)
    #id that corresponds 'id' attribute of right tag 
    #Basically it's name of a variable or a function
    id = row[7]
    #Set 'internalidaddress' tag
    if id == '_VERSION':
        xml_root.find('.//internalidaddress').text = address
        continue
    #Find all tags that have
    #attribute 'id' equal to what we are searching
    tags = xml_root.xpath(f'//table[@id="{id}"] | //state[@id="{id}"]')
    #Process every element
    for t in tags:
        #Every table must contain an address attribute
        if id.startswith('_CFG_') or id.startswith('_tbl'):
            t.set('storageaddress', address)
        #Parent element of X or Y axis must have size attribute for every axis
        #Check for X axis
        if id.startswith('_tbl') and id.endswith('_x_axis'):
            #Some 2D tables could have Y axis instead X
            #Set proper name of axis size attribute here
            sizex = ''
            if t.get('type') == 'X Axis':
                sizex = 'sizex'
            elif t.get('type') == 'Y Axis':
                sizex = 'sizey'
            if len(sizex) > 0:
                t.getparent().set(sizex, size_str)
        #Check for Y axis
        if id.startswith('_tbl') and id.endswith('_y_axis'):
            t.getparent().set('sizey', size_str)
        #Entry point
        if id.endswith('_entry_point'):
            #Split the address into groups of characters separated by space 
            data_string = ' '.join(re.findall(r'.{2}', address))
            t.set('data', data_string)
        #We don't want 'id' attribute to be present in definitions file
        t.attrib.pop('id')

#Prepare output to a XML file
tree = ET.ElementTree()
tree._setroot(xml_root)
if OUTPUT_TO_STDOUT:
    print(ET.tostring(tree, pretty_print=True, encoding="utf-8", xml_declaration=True).decode())
else:
    tree.write(output_file_name, pretty_print=True, encoding="utf-8", xml_declaration=True)


