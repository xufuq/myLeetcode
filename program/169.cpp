#include <map>
#include <queue>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> temp;
    for(auto n : nums) 
        temp[n]++;

    for(auto n : temp)
        if(n.second>nums.size()/2) return n.first;
    
}