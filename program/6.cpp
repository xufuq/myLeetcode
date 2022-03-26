//
// Created by Dell on 2021/3/28.
//

#ifndef PROGRAM_NO6_H
#define PROGRAM_NO6_H
#include <string>
using namespace std;

string convert(string s, int numRows) {
    if (numRows==1)
        return s;
    int sLen = s.size(), step = 2*numRows-2;
    string retStr;
    for (int L0=0;L0<sLen;L0+=step)
        retStr += s[L0];
    for (int n=1;n<numRows-1;n++) {
        for (int L0=0;L0<sLen+numRows;L0+=step){
            if (L0-n>0&&L0-n<sLen)
                retStr += s[L0-n];
            if (L0+n<sLen)
                retStr += s[L0+n];
        }
    }
    for (int L0=numRows-1;L0<sLen;L0+=step)
        retStr += s[L0];
    return retStr;
}


#endif //PROGRAM_NO6_H
