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
#include <time.h>
using namespace std;

// 访问后就置零，如果访问到0说明有循环
// 循环的条件很严格
int getNextIndex(int index, int n) {
    index%=n;
    index=index>=0?index:index+n;
    return index;
}
bool circularArrayLoop(vector<int>& nums) {
    int n=nums.size(), flag=0; // flag代表当前的符号是正的或者负的，0代表未取到符号
    vector<int> visited(n, -1); // 里面记录的数字代表是从下标i开始的
    for(int i=0;i<n;++i) {
        if(visited[i]!=-1) continue; // 不能用的废废循环
        else if(getNextIndex(nums[i]+i, n)==i)  // 自身成环
            visited[i]=i;
        else {
            // 刚开辟的一个可能循环
            visited[i]=i;
            if(nums[i]>0) flag=1;
            else if(nums[i]<0) flag=-1;
            else continue;
            int nextIndex=getNextIndex(nums[i]+i, n);
            while((nums[nextIndex]>0 && flag==1) || (nums[nextIndex]<0 && flag==-1)) {
                if(visited[nextIndex]==i) 
                    return true;
                else if(visited[nextIndex]==-1) {
                    visited[nextIndex]=i;
                    int j=getNextIndex(nums[nextIndex]+nextIndex, n);
                    if(j==nextIndex) break; // 防止自身成环
                    else nextIndex=j;
                }
                else
                    break;
            }
        }
    }
    return false;
}