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

int result = 0;

// 时间复杂度太高
// void pathSum(TreeNode* root, int totalSum, int curSum, bool isRoot) {
//     if(root == nullptr) return;
//     if(isRoot) { // 是根节点，从当前节点开始
//         pathSum(root->left, totalSum, totalSum-root->val, false); // 包含当前节点
//         pathSum(root->right, totalSum, totalSum-root->val, false);
//         pathSum(root->left, totalSum, totalSum, true);
//         pathSum(root->right, totalSum, totalSum, true);
//     } else {
//         pathSum(root->left, totalSum, curSum-root->val, false); // 包含当前节点
//         pathSum(root->right, totalSum, curSum-root->val, false);
//     }
    
//     if(curSum==root->val) {
//         ++result;
//         cout << result << " " << root->val << endl;
//     }
// }

// int pathSum(TreeNode* root, int targetSum) {
//     pathSum(root, targetSum, targetSum, true);
//     return result;
// }

// 这个函数返回包括当前节点能够组成的所有数的可能
vector<int> pathDfs(TreeNode* root, int targetSum) {
    vector<int> left, right;
    if(root->left) left=pathDfs(root->left, targetSum);
    if(root->right) {
        right=pathDfs(root->right, targetSum);
        left.insert(left.end(), right.begin(), right.end());
    }
    if(root->val==targetSum) ++result;
    for(auto &n : left){
        if(n+root->val==targetSum) ++result;
        n+=root->val;
    }
    left.push_back(root->val);
    return left;
}

int pathSum(TreeNode* root, int targetSum) {
    if(!root) return 0;
    pathDfs(root, targetSum);
    return result;
}

// 大佬做的方法
// 很好
class Solution {
    int pathSum(TreeNode *root, int sum) {
        if (root) {
            return 0;
        }
        return calPathSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int calPathSum(TreeNode *root, int sum) {
        if (root) {
            return 0;
        }
        int tmp = 0;
        sum -= root->val;
        if (sum == 0) {
            tmp++;
        }
        return tmp + calPathSum(root->left, sum) + calPathSum(root->right, sum);
    }
};