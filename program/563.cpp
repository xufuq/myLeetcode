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

int getSum(TreeNode *root, int result) {
    if(root == nullptr) return 0;
    int left=getSum(root->left, result);
    int right=getSum(root->right, result);
    result+=abs(left-right);
    return left+right+root->val;
}

int findTilt(TreeNode* root) {
    int result=0;
    getSum(root, result);
    return result;
}