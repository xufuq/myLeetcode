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

// 遍历所有节点，然后把一个标号赋给每个节点
// 当前层数， 当前节点编号
void widthOfBinaryTree(TreeNode* root, unsigned long level, unsigned long rootNum, vector<vector<unsigned long>> &widthLR) {
    if(root == nullptr) return;
    if(widthLR.size()<level+1) {
        widthLR.push_back(vector<unsigned long>());
        widthLR[level].push_back(rootNum);
    }
    else if(widthLR[level].size()==1)
        widthLR[level].push_back(rootNum);
    else if(widthLR[level].size()==2)
        widthLR[level][1]=rootNum;
    widthOfBinaryTree(root->left, level+1, 2*rootNum, widthLR);
    widthOfBinaryTree(root->right, level+1, rootNum*2+1, widthLR);
}


int widthOfBinaryTree(TreeNode* root) {
    vector<vector<unsigned long>> widthLR;
    widthOfBinaryTree(root, 0, 1, widthLR);
    unsigned long result=1;
    for(auto &width:widthLR)
        if(width.size()==2)
            result=max(result, width[1]-width[0]+1);
    return (int)result;
}

// 官方题解用宽度优先搜索，先搜索每一层，这样不用记录