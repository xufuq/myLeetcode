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

TreeNode* addOneRow(TreeNode* root, int val, int depth, bool left) {
    if(depth==1) return new TreeNode(val, left?root:nullptr, left?nullptr:root);
    if(root==nullptr) return nullptr;
    root->left=addOneRow(root->left, val, depth-1, true);
    root->right=addOneRow(root->right, val, depth-1, false);
    return root;
}

// 深度优先搜索，到达指定层数后就不再继续深入搜索
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    return addOneRow(root, val, depth, true);
}