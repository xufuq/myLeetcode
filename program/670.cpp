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

int maximumSwap(int num) {
    if(num<=10) return num;
    string str=to_string(num);
    char maxC='0';
    int maxIndex = 0, curIndex = 0;
    for(int i = 0; i < str.length(); i++) {
        char maxC=str[i];
        maxIndex = i, curIndex = i;
        for(int j = i; j < str.length(); j++) {
            if(str[j] >= maxC) {
                maxC=str[j];
                maxIndex = j;
            }
        }
        if(maxIndex!=i && str[maxIndex]!=str[curIndex]) break;
    }
    swap(str[maxIndex], str[curIndex]);
    return stoi(str);
}