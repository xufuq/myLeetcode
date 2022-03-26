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

bool findTarget(TreeNode* root, int k, unordered_set<int> &target) {
    if(root==nullptr) return false;
    if(target.count(root->val)) return true;
    target.insert(k-root->val);
    return findTarget(root->left, k, target) || findTarget(root->right, k, target);
}

bool findTarget(TreeNode* root, int k) {
    unordered_set<int> target;
    return findTarget(root, k, target);
}