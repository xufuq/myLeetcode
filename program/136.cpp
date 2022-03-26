#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_set<int> nset;
    for(auto n : nums) {
        if(nset.count(n)==0)
            nset.insert(n);
        else 
            nset.erase(n);
    }
    auto it=nset.begin();
    return *it;
}

// 用异或运算