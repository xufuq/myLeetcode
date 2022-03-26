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

void mergeTrees(TreeNode* &result, TreeNode* root1, TreeNode* root2) {
    if(root1 && root2){ // 都不为空
        result = new TreeNode(root1->val+root2->val);
        mergeTrees(result->left, root1->left, root2->left);
        mergeTrees(result->right, root1->right, root2->right);
    }
    else if(root1)
        result = root1;
    else
        result = root2;
}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    TreeNode* node=nullptr;
    mergeTrees(node, root1, root2);
    return node;
}

// 用一个函数解决
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    TreeNode* node;
    if(root1 && root2){ // 都不为空
        node = new TreeNode(root1->val+root2->val);
        node->left = mergeTrees(root1->left, root2->left);
        node->right = mergeTrees(root1->right, root2->right);
    }
    else if(root1)
        node = root1;
    else
        node = root2;
    return node;
}