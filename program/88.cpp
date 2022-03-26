#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include "math.h"
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    reverse(nums1.begin(), nums1.begin()+m);
    reverse(nums2.begin(), nums2.end()); //
    int start=0, start1=m, start2=0;
    while(start2<n) {
        if(nums1[start1]>=nums2[start2]) 
            nums1[start++] = nums2[start2++];
        else 
            nums1[start++] = nums1[start1++];
    }
}
