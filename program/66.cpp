#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    bool getIn = false;
    int i=digits.size()-1;
    do{
        digits[i] +=1;
        if(digits[i]==0) getIn=true;
        else getIn = false;
        --i;
    }while(getIn && i>=0);
    if(getIn) digits.insert(digits.begin(), 1);
    return digits;
}