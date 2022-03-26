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

string fractionAddition(string expression) {
    int sIndex1=0, sIndex2=0;
    vector<vector<int>> numRecord;
    vector<int> record(2);
    for(int i=1;i<expression.length();i++) {
        if(expression[i]=='/') {
            record[0]=stoi(expression.substr(sIndex1, i-sIndex1));
            sIndex2=i+1;
        }
        else if(expression[i]=='+' || expression[i]=='-' || i==expression.length()-1) {
            if(i==expression.length()-1)
                record[1]=stoi(expression.substr(sIndex2, i-sIndex2+1));
            else
                record[1]=stoi(expression.substr(sIndex2, i-sIndex2+1));
            sIndex1=i;
            numRecord.push_back(record);
        }
    }
    int bom=1, sum=0;
    for(auto &v : numRecord) 
        bom*=v[1];

    for(auto &v : numRecord)
        sum+=bom/v[1]*v[0];
    if(sum==0)
        bom=1;
    else {
        for(int i=2;i<=abs(sum) && i<=bom;){
            if(sum%i==0 && bom%i==0) sum/=i, bom/=i;
            else ++i;
        }
    }
    return to_string(sum)+"/"+to_string(bom);
}

// 官方题解编写了一个求解最大公约数的公式