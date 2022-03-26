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

// 返回值是第二小的数
int findSecondMinimumValue(TreeNode* root) {
    if(root->left==nullptr) return -1; // 两个节点都为空
    if(root->left->val==root->right->val) { // 左右节点的值相等
        int left=findSecondMinimumValue(root->left);
        int right=findSecondMinimumValue(root->right);
        if(left==-1 && right==-1)
            return -1;
        else if(left==-1)
            return right;
        else if(right==-1)
            return left;
        else
            return min(left, right);
    }
    else if(root->left->val==root->val) {
        int left=findSecondMinimumValue(root->left);
        if(left==-1) return root->right->val;
        else return min(left, root->right->val);
    } else {
        int right=findSecondMinimumValue(root->right);
        if(right==-1) return root->left->val;
        else return min(right, root->left->val);
    }
}