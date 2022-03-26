#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    map<int, int> res;
    for(int i=0;i<mat.size();i++) {
        int count = 0;
        for(auto &n : mat[i]) {
            if(n) ++count;
        }
        res.insert(pair<int, int>(count, i));
    }
    vector<int> result;
    auto it = res.begin();
    while(result.size()<k){
        result.push_back(it->first);
        ++it;
    }
    return result;
}

bool less1(const vector<int> &a, const vector<int> &b) {
    if(a[0]<b[0]) return true;
    else if(a[0]>b[0]) return false;
    else{
        if(a[1]<b[1]) return false;
        else return true;
    }
}

// 上面同一数量军人的顺序不对
// 可以自定义比较函数，用sort函数实现
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<vector<int>> vec;
    for(int i=0;i<mat.size();i++) {
        int count = 0;
        for(auto &n : mat[i]) {
            if(n) ++count;
        }
        vec.push_back({count, i});
    }
    sort(vec.begin(), vec.end(), less1);
    vector<int> result(k);

    for(int i=0;i<k;++i)
        result[i]=vec[i][1];

    return result;
}

// 看官方题解，关键是怎么计算军人数量
// 然后用小根堆存，优先级队列
// move关键字的用法