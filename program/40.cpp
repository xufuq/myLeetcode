#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

set<vector<int>> result;

void combinationSum(vector<int>& candidates, vector<int>& path, int target, int currentIndex) {
    if(target==0)
        result.insert(path);
    else{
        int lastNum=0;
        for(int i=currentIndex; i<candidates.size() && target>=candidates[i];++i){
            if(lastNum==candidates[i]) continue; // 记录上次取到的元素，防止重复浪费时间
            else lastNum=candidates[i];
            path.push_back(candidates[i]);
            combinationSum(candidates, path, target-candidates[i], i+1);
            path.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // 默认升序排序
    vector<int> path;
    combinationSum(candidates, path, target, 0);
    return vector<vector<int>>(result.begin(), result.end());
}
