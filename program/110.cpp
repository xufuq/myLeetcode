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

bool getDepth(TreeNode* root, int& depth){
    if(!root){
        depth = 0;
        return true;
    }
    int lDepth=0, rDepth=0;
    if(!getDepth(root->left, lDepth)) return false;
    if(!getDepth(root->right, rDepth)) return false;
    if(max(lDepth,rDepth)-min(lDepth,rDepth)<2) {
        depth=max(lDepth,rDepth)+1;
        return true;
    }
    return false;
}

bool isBalanced(TreeNode* root) {
    int depth;
    return getDepth(root, depth);
}