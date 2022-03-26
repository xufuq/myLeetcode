#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// 这里使用的优先级队列，即小根堆对元素进行了排列
class mycomparsion {
public:
    bool operator() (const pair<const int, int> &a, const pair<const int, int> &b){
        return a.second > b.second;
    }
};

// map+queue
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> countNum;
    for(auto n : nums) 
        countNum[n]++;
    priority_queue<pair<const int, int>, vector<pair<const int, int>>, mycomparsion > resultQueue;
    for(auto &m : countNum){
        resultQueue.push(m);
        if(resultQueue.size()>k)
            resultQueue.pop();
    }
    vector<int> result;

    while(resultQueue.size()){
        result.push_back(resultQueue.top().first);
        resultQueue.pop();
    }
    return result;
}