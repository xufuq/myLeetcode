#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
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

vector<string> result;
void binaryTreePaths(TreeNode* root, string str) {
    str+=to_string(root->val);
    if(!root->left && !root->right) result.push_back(str);
    else {
        str+="->";
        if(root->left) binaryTreePaths(root->left, str);
        if(root->right) binaryTreePaths(root->right, str);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    if(!root) return result;
    string str;
    binaryTreePaths(root, str);
    return result;
}