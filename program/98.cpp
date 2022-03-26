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

bool isValidBST(TreeNode* root, int &minN, int &maxN){
    if(!root) return true;
    int leftMin, rightMin, leftMax, rightMax;
    if(!isValidBST(root->left, leftMin, leftMax) || !isValidBST(root->right, rightMin, rightMax)) return false; // 如果子树不为真
    if(root->left==nullptr)       minN=root->val;
    else if(root->val <= leftMax) return false;
    else                          minN = leftMin;

    if(root->right==nullptr)      maxN=root->val;
    else if(root->val >= rightMin)return false;
    else                          maxN = rightMax;
    return true;
}

bool isValidBST(TreeNode* root) {
    int a,b;
    return isValidBST(root, a, b);
}

// 简化版
bool isValidBST(TreeNode* root) {
    if(!root) return true;
    TreeNode* node=root->left;
    if(node!=nullptr){
        while(node->right!=nullptr)
            node=node->right;
        if(node->val >= root->val)
            return false;
    }
    node=root->right;
    if(node!=nullptr){
        while(node->left!=nullptr)
            node=node->left;
        if(node->val <= root->val)
            return false;
    }
    if(!isValidBST(root->left) || !isValidBST(root->right)) return false;
    return true;
}

// 官方题解1
// 指定上下界
class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

// 官方题解2
// 中序遍历一定是升序的
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long long inorder = (long long)INT_MIN - 1;

        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
            if (root -> val <= inorder) {
                return false;
            }
            inorder = root -> val;
            root = root -> right;
        }
        return true;
    }
};
