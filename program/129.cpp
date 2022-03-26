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

void sumNumbers(TreeNode* root, int &result, int &path) {
    path=path*10+root->val;
    if(root->left==nullptr && root->right==nullptr) {
        result+=path;
        path/=10;
        return;
    } 
    if(root->left) sumNumbers(root->left, result, path);
    if(root->right) sumNumbers(root->right, result, path);
    path/=10;
}

int sumNumbers(TreeNode* root) {
    int result=0, int path=0;
    sumNumbers(root, result, path);
    return result;
}