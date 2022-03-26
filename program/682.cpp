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

int calPoints(vector<string>& ops) {
    stack<int> scores;
    for(auto &str : ops) {
        if(str=="+") {
            int num1=scores.top();
            scores.pop();
            int num2=scores.top();
            scores.push(num1);
            scores.push(num2+num1);
        } 
        else if(str=="D") 
            scores.push(scores.top()*2);
        else if(str=="C")
            scores.pop();
        else {
            int num1=stoi(str);
            scores.push(num1);
        }
    }
    int result=0;
    while(!scores.empty()) {
        result+=scores.top();
        scores.pop();
    }
    return result;
}