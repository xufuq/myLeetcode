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


// 两棵树重复是指从当前节点到叶子节点都一样
// 可以用字符串保存当前节点的前序遍历结果，然后对比字符串结果,中左右
string getString(TreeNode* root, unordered_set<TreeNode*> &result, unordered_map<string, int> &path) {
    string str;
    if(root==nullptr) return "#";
    str=to_string(root->val);
    str+="," + getString(root->left, result, path);
    str+="," + getString(root->right, result, path);
    if(path.count(str)) {
        if(path[str]==0) {
            result.insert(root);
            ++path[str];
        }
    }
    else path[str]=0;
    return str;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int>  path;
    unordered_set<TreeNode*> result;
    getString(root, result, path);
    return vector<TreeNode*>(result.begin(), result.end());
}