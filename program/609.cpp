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

vector<vector<string>> findDuplicate(vector<string>& paths) {
    string dir, name, content;
    unordered_map<string, vector<string>> files;
    for(auto &path : paths) {
        stringstream is(path);
        is>>dir;
        is>>name;
        int left=0;
        for(int i=0;i<name.length();i++) {
            if(name[i]=='(') {
                left=i;
                break;
            }
        }
        content=name.substr(left+1, name.length()-left-2);
        name=name.substr(0, left);
        files[content].push_back(dir+"/"+name);
    }
    vector<vector<string>> result;
    for(auto &m:files) {
        if(m.second.size()>1) 
            result.push_back(m.second);
    }
    return result;
}