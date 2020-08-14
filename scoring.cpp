#include "scoring.h"
/**cvss기준으로 점수 평가*/
int cvss_score(int* passfail){
    int score=0;
    for(int i=0; i<len(passfail); i++){
        score+=cvss(passfail[i]);
    }
}
