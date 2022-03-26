#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <functional>
using namespace std;

// 用双指针找左右范围
int peakIndexInMountainArray(vector<int>& arr) {
    int left=0, right=arr.size()-1, mid=(left+right)/2;
    while(left<=right) {
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
            return mid;
        else if(arr[mid-1]<arr[mid]) { // 上升阶段
            left = mid+1;
            mid=(left+right)/2;
        }
        else { // 下降阶段
            right=mid;
            mid=(left+right)/2;
        }
    }
    return mid;
}