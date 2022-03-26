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

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        count=0;
    }
    
    void addNum(int num) {
        ++nums[num];
        ++count;
    }
    
    double findMedian() {
        int mid=count/2, D=count%2;
        int addNum=0;
        for(auto it=nums.begin(); it!=nums.end();++it) {
            addNum += it->second;
            if(D) { // 只需要一个数
                if(addNum>=mid) 
                    return (double)it->first;
            }
            else {
                int sum=0;
                if(addNum==mid-1) {
                    sum+=it->first;
                    ++it;
                    sum+=it->first;
                    return sum/2.0;
                } else if(addNum>=mid) {
                    sum+=it->first * 2;
                    return sum/2.0;
                }
            }          
        }
    }
private:
    int count;
    map<int, int> nums;
};

// 官方题解是用两个优先级队列维护中位数