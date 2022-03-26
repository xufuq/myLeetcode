#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <map>

using namespace std;

// 贪心算法，使得船每次载客量尽量大
// 在所有人中寻找组合，每个组合的重量越靠近limit越好
// 且最多同时两人,所以尽量保证一条船有两个人
// 这个时间复杂度太高
// int numRescueBoats(vector<int>& people, int limit) {
//     // 先sort，先把重量大的装上
//     map<int, int> pMap; // 重量-人数
//     for(auto p : people)  // 统计人数
//         pMap[p]++;
    
//     int result=0;
//     for(auto it=pMap.rbegin();it!=pMap.rend();++it){
//         while(it->second!=0){
//             int curLeft=limit, curCount=0;
//             auto pc = it;
//             while(curCount<2 && curLeft!=0 && pc!=pMap.rend()){
//                 if(pc->second!=0 && curLeft>=pc->first){
//                     curLeft-=pc->first;
//                     pc->second--;
//                     curCount++;
//                 }
//                 else ++pc;
//             }
//             ++result;
//         }
//     }
//     return result;
// }

// 因为保证最多两个人，所以直接首尾结合好像也可以
int numRescueBoats(vector<int>& people, int limit) {
    // 先sort，先把重量大的装上，然后匹配一个重量最小的，然后双指针
    sort(people.begin(), people.end());
    int startIndex=0, endIndex=people.size()-1, result=0;
    while(startIndex<endIndex){
        if(people[endIndex] + people[startIndex]<=limit)
            --endIndex, ++startIndex;
        else 
            --endIndex;
        ++result;
    }
    if(startIndex==endIndex) ++result;
    return result;
}

int main(){
    vector<int> people={3, 2, 3, 2, 2};
    cout << numRescueBoats(people, 5);
    cout << "over" <<endl;
}