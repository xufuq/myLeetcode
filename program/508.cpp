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

int getSum(TreeNode *root, unordered_map<int, int> &mp, int &maxCount) {
    if(root == nullptr) return 0;
    int left=getSum(root->left, mp, maxCount);
    int right=getSum(root->right, mp, maxCount);
    int sum=left+right+root->val;
    ++mp[sum];
    maxCount=max(maxCount, mp[sum]);
    return sum;
}


vector<int> findFrequentTreeSum(TreeNode* root) {
    unordered_map<int, int> mp;
    int maxCount=0;
    vector<int> result;
    getSum(root, mp, maxCount);
    for(auto &p : mp) {
        if(p.second==maxCount)
            result.push_back(p.first);
    }
    return result;
}