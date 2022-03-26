#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

// 从两个方向对比各自自增
// 
int candy(vector<int>& ratings) {
    int len = ratings.size();
    vector<int> reults(len, 1);

    for(int i=1; i<len; ++i) 
        if(ratings[i]>ratings[i-1])
            reults[i]=reults[i-1]+1;

    for(int i=len-2;i>=0; --i){
        if(ratings[i]>ratings[i+1])
            reults[i]=max(reults[i+1]+1, reults[i]); // 因为之前这个数有可能被用过，这个就是用来解决有上升到下降的峰值的问题的， 相等的除了左右两边默认为1没问题
    }
    return accumulate(reults.begin(), reults.end(), 0);
}

int main(){
    vector<int> nums={1, 0, 2};
    cout << candy(nums) << endl;
}