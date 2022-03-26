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

// 从后面找第一个小于其后面的数的数字
// 然后交换比其大的最小的数
// 然后后面的数最小排序
int nextGreaterElement(int n) {
    string str=to_string(n);
    vector<int> posMem(10, -1);
    int posBit=0;
    for(int i=str.size()-1;i>=0;--i) {
        int curN=str[i]-'0';
        if((posBit>>(curN+1))>0) { // 找到了可以交换的位置
            ++curN;
            while(posMem[curN]==-1) 
                ++curN;
            swap(str[i], str[posMem[curN]]);
            sort(str.begin()+i+1, str.end());
            break;
        }
        else { //没有符合条件的，执行标志位
            posMem[curN]=i;
            posBit|=1<<curN;
        }
    }
    if(str==to_string(n) || (str.size()==10 && str.compare(to_string(INT_MAX))>0))
        return -1;
    return stoi(str);
}