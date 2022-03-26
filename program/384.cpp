#include <map>
#include <set>
#include <queue>
#include <string>
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        nowVec=nums;
        srand((int)time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nowVec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n=nowVec.size();
        vector<int> result(n);
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++) {
            int index=rand()%n;
            while(visited[index])
                index=rand()%n;
            visited[index]=true;
            result[i]=nowVec[index];
        }
        return result;
    }
private:
    vector<int> nowVec;
};