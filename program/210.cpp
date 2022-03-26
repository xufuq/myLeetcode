#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <stack>
using namespace std;

// 验证是否有环，如果有则无法
// 深度优先搜索完成排序

// 返回是否有可行解，如果有环则不可行

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> orderNext;
    vector<int> inCount(numCourses), result;
    stack<int> emptyInput;
    for(auto &p : prerequisites) {
        orderNext[p[1]].push_back(p[0]);
        ++inCount[p[0]];
    }
    for(auto course : inCount) {
        if(course==0) emptyInput.push(course);
    }
    while(!emptyInput.empty()) {
        int course=emptyInput.top();
        emptyInput.pop();
        result.push_back(course);
        for(auto nextCourse : orderNext[course]) {
            --inCount[nextCourse];
            if(inCount[nextCourse]==0) 
                emptyInput.push(nextCourse);
        }
    }
    if(result.size()==numCourses)
        return result;
    return vector<int>();    
}