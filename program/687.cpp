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

int maxLen=0;
// 返回值应该是包含当前节点的最长路径的长度
int curNodeLen(TreeNode* root) {
    if(root==nullptr) return 0;
    int curPath=0, curLen=0;
    int leftLen=curNodeLen(root->left);
    if(root->left!=nullptr && root->left->val==root->val) {
        curPath+=leftLen+1;
        curLen=max(curLen, leftLen+1);
    }
    int rightLen=curNodeLen(root->right);
    if(root->right!=nullptr && root->right->val==root->val) {
        curPath+=rightLen+1;
        curLen=max(curLen, rightLen+1);
    }
    maxLen=max(maxLen, curPath);
    return curLen;
}

int longestUnivaluePath(TreeNode* root) {
    curNodeLen(root);
    return maxLen;
}