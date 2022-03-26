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

int sumOfLeftLeaves(TreeNode* root, bool isLeft) {
    if(root->left == nullptr && root->right == nullptr){
        if(isLeft) return root->val;
        else return 0;
    }
    int leftSum = 0, rightSum = 0;
    if(root->left!=nullptr) leftSum = sumOfLeftLeaves(root->left, true);
    if(root->right!=nullptr) rightSum = sumOfLeftLeaves(root->right, false);
    return leftSum + rightSum;
}

int sumOfLeftLeaves(TreeNode* root) {
    return sumOfLeftLeaves(root, false);
}