//
// Created by Dell on 2021/4/7.
//

#ifndef PROGRAM_NO9_H
#define PROGRAM_NO9_H
#include <string>
using namespace std;

bool isPalindrome(int x) {
    if (x<0)
        return false;
    else{
        string str = to_string(x);
        int len=str.size();
        for (int i=0;i<len;i++)
            if (str[i]!=str[len-1-i])
                return false;
    }
    return true;
}




#endif //PROGRAM_NO9_H
