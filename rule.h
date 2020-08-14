#pragma once
#include <string>
#include <iostream>
using namespace std;
/**검사 룰을 표현한 클래스*/
struct Rule final{
    string definition; /**룰을 정의*/
    string test; /**검사 항목들을 연결*/
    string object;/**검사를 위한 객체*/
    string state;/**검사 및 평가 수행*/
    string fixation;/**fail항목 수정*/
    Rule(string def, string tst, string obj, string st, string fix){definition=def; test=tst; object=obj; state=st; fixation=fix;}
};