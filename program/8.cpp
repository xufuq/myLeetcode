//
// Created by Dell on 2021/4/6.
//
#include <string>
#include <limits>

using namespace std;

#ifndef PROGRAM_NO8_H
#define PROGRAM_NO8_H

int myAtoi(string s){
    int sign = 1, isNum=0, num=0;
    for(auto c : s){
        if (c>='0' && c<='9'){
            int nowNum=c-'0';
            isNum=1;
            if ((num>INT_MAX/10 || (num==INT_MAX/10 && nowNum>7)))
                return INT_MAX;
            else if ((num<INT_MIN/10 || (num==INT_MIN/10 && nowNum>8)))
                return INT_MIN;
                num=10*num+sign*nowNum;
        }
        else if(c==' '&&isNum==0)
            continue;
        else if (isNum==0&&(c=='-' || c=='+'))// 两个正负号
            sign= c=='-'?-1:1, isNum=1;
        else
            break;
    }
    return num;
}


#endif //PROGRAM_NO8_H

