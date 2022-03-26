#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include "math.h"
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    vector<int> visited(nums.size()+1), result(2);
    for(auto n : nums) 
        ++visited[n];
    for(int i=1;i<visited.size();++i){
        if(visited[i]==2)
            result[0]=i;
        else if(visited[i]==0)
            result[1]=i;
    }
    return result;
}