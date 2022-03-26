//
// Created by Dell on 2021/3/28.
//

#ifndef PROGRAM_NO7_H
#define PROGRAM_NO7_H
#include <vector>
#include <cmath>

using namespace std;

int reverse(int x) {
    int abs = 0,flag=0, mi=0;
    long num=0;
    if (x>0)
        abs=1;
    else if (x<0){
        abs=-1;
        x=-x;
    }
    else
        return x;
    vector<int> vec(10);
    vec[0] = x%10;
    vec[9] = x/long(powl(10, 9));
    for (int n=1;n<9;n++)
        vec[n] = (x%long(powl(10, n+1)))/long(powl(10, n));
    for (int n=9;n>=0;--n){
        cout << vec[n] << " ";
        if (vec[n]!=0)
            flag = 1;
        if (flag==1) {
            num += vec[n] * long(powl(10, mi));
            ++mi;
        }
    }
    num *= abs;
    if(num < -powl(2,31) || num > powl(2,31)-1)
        num = 0;
    return num;
}
#endif //PROGRAM_NO7_H
