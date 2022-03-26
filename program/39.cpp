#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> result;

void combinationSum(vector<int>& candidates, vector<int>& path, int target, int currentIndex) {
    if(target==0)
        result.push_back(path);
    else{
        for(int i=currentIndex; i<candidates.size() && target>=candidates[i];++i){
            path.push_back(candidates[i]);
            combinationSum(candidates, path, target-candidates[i], i);
            path.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // 默认升序排序
    vector<int> path;
    combinationSum(candidates, path, target, 0);
    return result;
}