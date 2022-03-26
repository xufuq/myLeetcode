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

TreeNode* searchBST(TreeNode* root, int val) {
    if(root == nullptr || root->val==val) return root;
    else if(root->val>val) return searchBST(root->left, val);
    else return searchBST(root->right, val);
}

// 这个题迭代也很简单
TreeNode* searchBST(TreeNode* root, int val) {
    while(root!=nullptr && root->val!=val){
        if(root->val > val) root = root->left;
        else if(root->val < val) root = root->right;
    }
    return root;
}