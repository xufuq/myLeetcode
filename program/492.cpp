#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include "math.h"
using namespace std;


vector<int> constructRectangle(int area) {
    int left=2, right=area/2;
    vector<int> result={area,1};
    while(left<=right) {
        if(left*right==area) {
            result[0]=right;
            result[1]=left;
        }
        ++left;;
        right=area/left;
    }
    return result;
}