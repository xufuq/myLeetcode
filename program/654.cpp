#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include "math.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* constructMaximumBinaryTree(vector<int>& nums, int startIndex, int endIndex) {
    int currentMax = -1, currentMaxIndex = -1;
    for(int i = startIndex; i < endIndex;++i) {
        if(nums[i]>currentMax){
            currentMax = nums[i];
            currentMaxIndex=i;
        }
    }

    TreeNode* node = new TreeNode(currentMax);
    if(startIndex!=currentMaxIndex)
        node->left = constructMaximumBinaryTree(nums, startIndex, currentMaxIndex);
    if(currentMaxIndex<endIndex-1)
        node->right = constructMaximumBinaryTree(nums, currentMaxIndex+1, endIndex);
    return node;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return constructMaximumBinaryTree(nums, 0, nums.size());
}