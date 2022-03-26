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
#include <queue>
using namespace std;

// 如果边上多，就往中间移动
// 如果中间多，就往边上移动
// 0会把这个移动强行中断，因为没有东西可以移动
int findMinMoves(vector<int>& machines, int sIndex, int eIndex, int ave) {
    cout << "sIndex: " << sIndex << " eIndex: " << eIndex << "        ";
    for(auto &m: machines) cout << m << " ";
    cout << endl;
    
    // 不需要移动的部分
    while(sIndex<eIndex && machines[sIndex]==ave) 
        ++sIndex;
    while(eIndex>sIndex && machines[eIndex-1]==ave)
        --eIndex;

    bool isDivided=false;
    int left=sIndex, right=left+1, result=0;
    int sum=0;
    while(right<=eIndex) {
        sum+=machines[right-1];
        if(sum==ave*(right-left)) {
            // 这里就是分而治之
            if(left!=sIndex || right!=eIndex) //没有分成功，手动分解
                isDivided=true;
            else
                break;
            result=max(result, findMinMoves(machines, left, right, ave));
            
            left=right;
            right=left+1;
            sum=0;
        }
        else
            ++right;
    }
    
    if(!isDivided && sIndex+1<eIndex) {
        // 这部分没有子模块，需要直接处理
        // cout << "is not divided" << endl;
        int start=sIndex, end=start;
        while(end<eIndex) {
            start=end;
            end=start+1;
            int sum=machines[start];
            if(sum<ave) {
                while(sum<ave*(end-start)) {
                    if(end>=eIndex) 
                        break; // 超出索引范围
                    sum+=machines[end];
                    // 如果当前元素为0的话是没有办法移动的
                    if(machines[end]==0) {
                        sum=0;
                        start=end;
                    }
                    ++end;
                }
                if(sum>=ave*(end-start)){
                    ++machines[start];
                    --machines[end-1]; // 因为自加过一次
                }
            }
            else if(sum>ave) { // sum>ave
                while(sum>ave*(end-start)) {
                    if(end>=eIndex) break;
                    sum+=machines[end];
                    ++end;
                    if(machines[end-1]==0) break;
                }
                if(sum<=ave*(end-start) || machines[end-1]==0) {
                    --machines[start];
                    ++machines[end-1];
                }
            }
        }
        return 1+findMinMoves(machines, sIndex, eIndex, ave);
    }
    return result;
}

int findMinMoves(vector<int>& machines) {
    int n=machines.size();
    int total=accumulate(machines.begin(), machines.end(), 0);
    if(total%n!=0) return -1;
    int ave=total/n;
    return findMinMoves(machines, 0, machines.size(), ave);
}

// 上面的方法可以完成，但是不是最少操作的方法
// 感觉可以用分而治之的方式

int main() {
    // vector<int> machines={0,0,10,0,0,0,10,0,0,0};
    // vector<int> machines={0,4,12,0};
    // vector<int> machines={0, 0, 11, 5};
    vector<int> machines={0,0,14,0,10,0,0,0};
    cout << findMinMoves(machines) << endl;
}