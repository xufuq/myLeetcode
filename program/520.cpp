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
#include "math.h"
using namespace std;

bool detectCapitalUse(string word) {
    int upperCount=1;
    for(auto &c : word) {
        if(isupper(c) && upperCount>0) ++upperCount;
        else if(islower(c)){
            if(upperCount>0)
                upperCount=-upperCount;
        }
        else return false; 
    }
    return true;
}