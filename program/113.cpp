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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void pathSum(TreeNode* root, int targetSum, vector<vector<int>> &result, vector<int> &path) {
    path.push_back(root->val);
    targetSum-=root->val;
    if(root->left==nullptr && root->right==nullptr) { // 叶子节点
        if(targetSum==0) result.push_back(path);
        path.pop_back();
        return;
    }
    // 未到叶子节点
    if(root->left)  pathSum(root->left, targetSum, result, path);
    if(root->right) pathSum(root->right, targetSum, result, path);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> result;
    if(root==nullptr) return result;
    vector<int> path;
    pathSum(root, targetSum, result, path);
    return result;
}