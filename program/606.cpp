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

void tree2str(TreeNode* root, string &result) {
    if(root == nullptr) return; //
    result+=to_string(root->val);
    if(root->left==nullptr && root->right==nullptr) return; //
    result.push_back('(');
    tree2str(root->left, result);
    result.push_back(')');
    if(root->right) {
        result.push_back('(');
        tree2str(root->right, result);
        result.push_back(')');
    }
}

string tree2str(TreeNode* root) {
    string result;
    tree2str(root, result);
    return result;
}