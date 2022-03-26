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

void printTree(TreeNode* root, vector<vector<string>> &result, int curCount, int curLevel) {
    if(result.size()<curLevel) 
        result.push_back(vector<string>(2*curLevel-1));
    result[curLevel-1][curCount]=to_string(root->val);
    if(root->left) printTree(root->left, result, curCount*2, curLevel+1);
    if(root->right) printTree(root->right, result, curCount*2+1, curLevel+1);
}

vector<vector<string>> printTree(TreeNode* root) {
    vector<vector<string>> result;
    printTree(root, result, 0, 1);
    int maxSize=result.back().size();
    for(auto &vec:result) {
        int half=(maxSize-vec.size());
        vector<string> ins(half, string());
        vec.insert(vec.begin(), ins.begin(), ins.end());
        vec.insert(vec.end(), ins.begin(), ins.end());
    }
    return result;
}