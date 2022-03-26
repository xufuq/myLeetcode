#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// 查看是否会形成闭环，如果有闭环则不行

class Solution {
public:
    bool canFinish(vector<vector<int>>& prerequisites, int nextCourse, unordered_set<int> usedNum){
        if(usedNum.count(nextCourse)) return false;
        else usedNum.insert(nextCourse);
        if(courses[nextCourse]) return true;
        for(int i=0;i<prerequisites.size();++i) {
            if(prerequisites[i][0]==nextCourse) {
                for(int j=i;j<prerequisites.size()&&prerequisites[j][0]==nextCourse;++j) 
                    if(!canFinish(prerequisites, prerequisites[j][1], usedNum)) return false;
                break;
            }
        }
        courses[nextCourse]=true;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        courses = vector<bool>(numCourses, false);
        sort(prerequisites.begin(), prerequisites.end());
        int lastCourse=-1;
        for(int i=0;i<prerequisites.size();++i) {
            vector<int> &pre=prerequisites[i];
            if(pre[0]-lastCourse>1){
                for(int i=lastCourse+1;i<pre[0];i++)
                    courses[i] = true;
            }
            lastCourse = pre[0];
            if(courses[pre[0]]) continue;
            unordered_set<int> myset;
            myset.insert(pre[0]);
            for(int j=i;j<prerequisites.size()&&prerequisites[j][0]==lastCourse;++j) {
                if(!canFinish(prerequisites, prerequisites[j][1], myset)) return false;
            }
            courses[pre[0]]=true;
        }
        return true;
    }

private:
    vector<bool> courses;
};

// 官方题解把所有同一个起点的点都放在一起
// 然后用一个course数组来记录这个点的搜索过程，012分别代表未搜索、搜索中和已搜索，这样便省去了set保存路径的空间