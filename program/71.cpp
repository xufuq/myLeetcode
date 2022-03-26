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

string simplifyPath(string path) {
    stack<string> stPath;
    int sIndex = 0;
    for(int i = 1; i < path.length();++i) {
        if(path[i] =='/') {
            if(i==sIndex+1) {
                sIndex=i;
                continue;
            }
            else {
                string p=path.substr(sIndex, i-sIndex);
                if(p=="/.") {
                    sIndex=i;
                    continue;
                }
                else if(p=="/..") {
                    if(!stPath.empty())
                        stPath.pop();
                }
                else
                    stPath.push(p);
            }
            sIndex=i;
        }
    }
    if(path.back()!='/') {
        string p=path.substr(sIndex, path.length()-sIndex);
        if(p=="/..") {
            if(!stPath.empty())
                stPath.pop();
        }
        else if(p!="/.")
            stPath.push(p);
    }
    if(stPath.empty()) return "/";
    string result;
    while(!stPath.empty()) {
        result=stPath.top()+result;
        stPath.pop();
    }
    return result;
}