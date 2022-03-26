#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
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


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    bool leftStart=false;
    queue<TreeNode*> myque;
    vector<vector<int> > result;
    if(!root) return result;
    result.push_back(vector<int>());
    myque.push(root);
    myque.push(nullptr);
    while(!myque.empty()){
        TreeNode *node=myque.front();
        myque.pop();
        if(!node) {
            leftStart=!leftStart;
            if(!myque.empty()) {
                result.push_back(vector<int>());
                myque.push(nullptr);
            }
        }
        else {
            result.back().push_back(node->val);
            if(leftStart) {
                if(node->left!=nullptr) myque.push(node->left);
                if(node->right!=nullptr) myque.push(node->right);
            }
            else {
                if(node->right!=nullptr) myque.push(node->right);
                if(node->left!=nullptr) myque.push(node->left);
            }
        }
    }
    return result;
}