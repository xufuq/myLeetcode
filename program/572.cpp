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

bool isSame(TreeNode* root, TreeNode* subRoot) {
    if(subRoot == nullptr && root==nullptr) return true;
    else if(subRoot == nullptr || root==nullptr) return false;
    else if(root->val==subRoot->val) 
        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    else    
        return false;
}   

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(root==nullptr) return false;
    if(isSame(root, subRoot)) return true;
    else return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}   