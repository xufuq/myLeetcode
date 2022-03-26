#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <stack>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp1;
    for(auto n1 : nums1) 
        ++nums1[n1];
    vector<int> result;
    for(auto n2 : nums2) {
        if(mp1[n2]) {
            result.push_back(n2);
            --mp1[n2];
        }
    }
    return result;
}