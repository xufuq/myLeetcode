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

// 双指针
vector<int> twoSum(vector<int>& numbers, int target) {
    int indexL=0, indexR=numbers.size()-1;
    while(indexL<indexR) {
        if(numbers[indexL]+numbers[indexR]>target)
            --indexR;
        else if(numbers[indexL]+numbers[indexR]<target)
            ++indexL;
        else
            return {indexL, indexR};
    }
    return {indexL, indexR};
}