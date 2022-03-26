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

int maxPath=0;

int dfs(TreeNode * root){
    int left=0, right=0;
    if(root->left) left=dfs(root->left);
    if(root->right) right=dfs(root->right);
    if(left+right>maxPath) maxPath=left+right;
    return max(left, right)+1;
}

int diameterOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    dfs(root);
    return maxPath;
}