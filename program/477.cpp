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

int totalHammingDistance(vector<int>& nums) {
    int n=nums.size(), result=0;
    vector<vector<int>> bitCount(32, vector<int>(2));
    for(int i=0; i<n;++i) {
        for(int j=0; j<32;++j) {
            if((nums[i]>>j)&1) ++bitCount[j][1];
            else               ++bitCount[j][0];
        }
    }
    for(int i=0; i<32;++i)
        result+=bitCount[i][0]*bitCount[i][1];
    return result;
}