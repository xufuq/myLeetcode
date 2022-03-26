#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// 对nums2遍历，然后查看nums1中是否存在当前这个元素
// 对nums2的遍历和每日温度的方式一样
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> umap;
    vector<int> result(nums1.size(), -1);
    stack<int> st;
    for(int i = 0; i < nums1.size();++i)
        umap[nums1[i]] = i; // 由数字查找到索引

    for(int i=0;i<nums2.size();++i){
        while(!st.empty() && nums2[i]>nums2[st.top()]){
            // 存在这个元素,得到的是这个元素的下标
            if(umap.count(nums2[st.top()])>0) result[umap[nums2[st.top()]]]=nums2[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}