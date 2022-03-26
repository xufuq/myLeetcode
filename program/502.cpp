#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 排序
// 利润降序或者成本升序
// 时间复杂度 太高
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n=profits.size();
    vector<vector<int>> table(n, vector<int>(3));
    for(int i=0; i<n; i++) {
        table[i][0]=1;
        table[i][1]=profits[i];
        table[i][2]=capital[i];
    }
    sort(table.begin(), table.end());
    while(k>0) {
        int i;
        for(i=n-1;i>=0;i--) {
            if(table[i][0] && table[i][2]<=w) {
                --k;
                table[i][0]=0;
                w+=table[i][1];
                break;
            }
        }
        if(i<0)
            return w;
    }
    return w;
}

// 利润降序或者成本升序
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n=profits.size();
    map<int, priority_queue<int, vector<int>, greater<int>>> mp; // 优先级队列不保证元素的唯一性, 升序队列
    for(int i=0;i<n;++i)
        mp[profits[i]].push(capital[i]);
    while(k>0) {
        auto m=mp.rbegin();
        for(; m!=mp.rend();++m){
            if(!(m->second.empty()) && m->second.top()<=w){
                --k;
                w+=m->first;
                m->second.pop();
                break;
            }
        }
        if(m==mp.rend()) return w;
    }
    return w;
}

int main(){
    vector<int> profits={1, 2, 3}, capital={0, 1, 1};
    cout << findMaximizedCapital(2, 0, profits, capital) << endl;
}