#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>

using namespace std;


vector<int> partitionLabels(string s) {
    bool isUsed[26]={false};
    vector<int> result;
    int startIndex=0, endIndex=0;
    for(int i=0;i<s.length();++i){
        if(isUsed[s[i]-'a']==false){
            endIndex=max((int)s.find_last_of(s[i]), endIndex);
            isUsed[s[i]-'a']=true;
        }
        if(i==endIndex){
            result.push_back(endIndex-startIndex+1);
            startIndex=endIndex+1;
        }
    }
    return result;
}