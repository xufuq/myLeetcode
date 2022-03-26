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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;  // 两个都是空
    if(!p || !q) return false; // 只有一个不是空
    return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}