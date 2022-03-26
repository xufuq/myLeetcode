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
#include <cstdlib>
#include <ctime>
using namespace std;

// 题目要求必须是常数时间复杂度
// 官方题解用动态数组做了优化
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand((int)time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(element.count(val)==0) {
            element.insert(val);
            return true;
        }
        else return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = element.find(val);
        if(it!=element.end()) {
            element.erase(it);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index=rand()%element.size();
        auto it=element.begin();
        while(index-->0) ++it;
        return *it;
    }
    unordered_set<int> element;
};