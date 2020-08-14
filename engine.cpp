#include "engine.h"
/**검사 수행 엔진*/
int* exec_engine(vector<Rule>& ruleset, int* pf){
    int passfail[200];
    vector<Rule>::iterator ptr;
    for(ptr=ruleset.begin(); ptr!=ruleset.end(); ptr++){
        if(check_regex()){
            /**정규식 검사*/
        }
        else{
            system(ptr->test);
        }
    }
    return passfail;
}
/**정규표현식 여부 검사*/
int check_regex(){
    /**정규표현식 여부 검사*/
}
/**루트 권한 체크*/
int check_authority(){
    /**루트 권한 체크*/
}
/**fix 수행*/
void fixation(Rule rule){
    /**fix 수행*/
}

