#include "xml_parser.h"
/**parsing xml line by line*/
Rule parse(char* xml_line){
    string split_xml[4];
    split_xml=split(xml_line);
    string definition=split_xml[0];
    string test=split_xml[1];
    string object=split_xml[2];
    string state=split_xml[3];
    string fixation=split_xml[4];
    Rule newrule=Rule(definition, test, object, state, fixation);
    return newrule;
}