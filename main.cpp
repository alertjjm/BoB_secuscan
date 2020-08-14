#include <cstdio>
#include <cstdlib>
#include <vector>
#include "rule.h"
#include "decrypt_xccdf.h"
#include "xml_parser.h"
#include "engine.h"
#include "scoring.h"
#include "display.h"
#include "pdf_report.h"
#include "html_report.h"
#define HTML 1
#define PDF 2
int main(){
    /**암호화된 xccdf 파일 읽기*/
    FILE *file = fopen("xccdf_sample.xml" , "rb");
    char xml_binary[200];
    if (file == NULL) { printf("파일을 읽기 모드로 열 수 없습니다.\n");
        return 0; 
    }
    fread(xml_binary , sizeof(xml_binary) , 1 , file);
    fclose(file);
    /**sha256 decryption */
    char* decrypted_xml=decrypt(PRIVATE_KEY, xml_binary);
    /**parsing rules*/
    vector<Rule> rule_set;
    for(int i=0; i<line; i++){
        Rule temp=decrypted_xml[i];
        rule_set.push_back(temp);
    }
    //*engine*/
    int passfail[200];
    memcpy(passfail, engine_run(rule_set),sizeof(int)*200);
    if(!check_authority()){
        printf("no authority!\n");
        exit(0);
    }
    memcpy(passfail, exec_engine(rule_set, passfail), sizeof(passfail));
    cvss_score(passfail);
    total_check_list(rule_set, passfail);
    int response;
    while(response=on_click(Save_button)){
        if(on_click(Result.fix)){
            fixation(rule_set[Result.index()]);
        }
    }
    create_html(rule_set, passfail);
    create_pdf(rule_set, passfail);
    switch (modify_category(response))
    {
    case HTML:
        show_final_score_status(HTML);
        break;
    case PDF:
        show_final_score_status(PDF);
        break;
    default:
        break;
    }
    return 0;
}