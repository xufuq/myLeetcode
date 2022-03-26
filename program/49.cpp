#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> res;
    for(auto &str : strs) {
        string sortStr = str;
        sort(sortStr.begin(), sortStr.end());
        res[sortStr].push_back(str);
    }
    vector<vector<string>> result;
    for(auto r : res) 
        result.push_back(r.second);

    return result;
}