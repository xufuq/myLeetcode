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

int currentLevel=0, maxLevel=0;
int Leftest = INT32_MIN;

int findBottomLeftValue(TreeNode* root) {
    ++currentLevel;
    if(root->left==nullptr && root->right==nullptr && currentLevel>maxLevel) {
        maxLevel=currentLevel;
        Leftest = root->val;
    }
    else {
        if(root->left!=nullptr) findBottomLeftValue(root->left);
        if(root->right!=nullptr) findBottomLeftValue(root->right);
    }
    return Leftest;
}