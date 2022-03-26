#include <vector>

using namespace std;

vector<vector<int>> result;

void combine(vector<int> &currentVec, int currentIndex, int n, int k){
    if(currentIndex>n) return;
    currentVec.push_back(currentIndex);
    if(currentVec.size()==k)
        result.push_back(currentVec);
    else
        combine(currentVec, currentIndex+1, n, k);
    currentVec.pop_back();
    combine(currentVec, currentIndex+1, n, k);
}

vector<vector<int>> combine(int n, int k) {
    vector<int> currentVec;
    combine(currentVec, 1, n, k);
    return result;
}

// 优化，把寻找大集合变为寻找小集合的问题

void combine(vector<int> &currentVec, int currentIndex, int n, int k){
    if(k==0){
        result.push_back(currentVec);
        return;
    }
    for(int i=currentIndex;k<=n-i+1;i++){
        currentVec.push_back(i);
        combine(currentVec,i+1, n, k-1);
        currentVec.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<int> currentVec;
    combine(currentVec, 1, n, k);
    return result;
}