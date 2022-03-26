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


int getMinimumDifference(TreeNode* root) {
    if(!root) return INT32_MAX;
    int minNum=INT32_MAX;
    TreeNode* node;
    if(root->left!=nullptr){
        node=root->left;
        while(node->right!=nullptr)
        node = node->right;
        if(abs(root->val - node->val) < minNum) minNum=abs(root->val - node->val);
    }
    if(root->right!=nullptr){
        node=root->right;
        while(node->left!=nullptr)
            node = node->left;
        if(abs(root->val - node->val) < minNum) minNum=abs(root->val - node->val);
    }
    int lefMinNum=getMinimumDifference(root->left);
    int rightMinNum=getMinimumDifference(root->right);
    if(lefMinNum<minNum) minNum=lefMinNum;
    if(rightMinNum<minNum) minNum=rightMinNum;
    return minNum;
}

// 变为有序数组，依次做差
// 这个解法很好，但是难以理解
int getMinimumDifference(TreeNode* root) {
    stack<TreeNode *> st;
    int result=INT32_MAX;
    TreeNode *cur=root, *pre=nullptr;
    while(cur !=nullptr || !st.empty()) {
        if(cur!=nullptr) {
            st.push(cur);
            cur=cur->left;
        }
        else{
            cur = st.top();
            st.pop();
            if(pre!=nullptr) result = min(result, cur->val - pre->val);
            pre=cur;
            cur=cur->right;
        }
    }
}