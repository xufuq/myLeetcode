#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    int len = people.size();
    sort(people.begin(), people.end());
    vector<bool> isUsed(len, false);
    vector<vector<int>> result(len);
    for(int i = 0; i <len; ++i) {
        int currentIndex, count=0;
        for(currentIndex = 0; currentIndex <len;++currentIndex) {
            if(!isUsed[currentIndex] || result[currentIndex][0]==people[i][0]) {
                if(count==people[i][1]) // 当前没有占用且排序合适
                    break;
                ++count;
            }
        }
        result[currentIndex]=people[i];
        isUsed[currentIndex]=true;
    }
    return result;
}