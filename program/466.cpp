#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include "math.h"
using namespace std;

// 求的结果是str1中包含几个str2
// 用哈希表找出循环节
int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int result = 0, s2Count = 0;
    unordered_map<int, vector<int>> one2two; //s1Index对应<N1Count, N2Count>
    // 还要判断多少个s1可以完整的对应s2
    int index1 = 0, index2=0, curN1=0, curN2=0;
    while(curN1!=n1) {
        if(s1[index1]==s2[index2]) 
            ++index2;
        ++index1;
        if(index2==s2.length()) {
            ++curN2;
            index2=0;
        }
        if(index1==s1.length()) {
            ++curN1;
            index1=0;
        }
        if(index2==0) { //当前完全匹配s2
            if(!one2two[index1].empty()) { // 之前也对应了一个结尾
                int lastN1=one2two[index1][0], lastN2=one2two[index1][1];
                int incN1=curN1-lastN1, incN2=curN2-lastN2;
                int leftN1=index1==0?n1-curN1 : n1-curN1-1; // 判断是否是从头开始
                curN2=curN2+leftN1/incN1*incN2;
                curN1=curN1+leftN1/incN1*incN1;
            }
            else
                one2two[index1]={curN1, curN2};
        }
    }
    return curN2/n2;
}