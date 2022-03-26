#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
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

// 一个重要前提就是没有重复元素
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    TreeNode* node = new TreeNode(postorder.back());
    int rootIndex=0;
    for(rootIndex=0; rootIndex<inorder.size(); rootIndex++)
        if(inorder[rootIndex]==postorder.back())
            break;
    if(rootIndex!=0){
        vector<int> leftInorder(inorder.begin(), inorder.begin()+rootIndex), leftPostorder(postorder.begin(), postorder.begin()+rootIndex);
        node->left=buildTree(leftInorder, leftPostorder);
    }
    if(rootIndex<postorder.size()-1){ // 右子树最少有一个元素
        vector<int> rightInorder(inorder.begin()+rootIndex+1, inorder.end()), rightPostorder(postorder.begin()+rootIndex, postorder.end()-1);
        node->right=buildTree(rightInorder, rightPostorder);
    }
    return node;
}


// 提高效率
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
    TreeNode* node = new TreeNode(postorder[postEnd-1]);
    int rootIndex=0;
    for(rootIndex=inStart; rootIndex<inEnd; rootIndex++) 
        if(inorder[rootIndex]==postorder[postEnd-1])
            break;

    if(rootIndex!=inStart)
        node->left=buildTree(inorder, postorder, inStart, rootIndex, postStart, postStart+rootIndex-inStart);
    if(rootIndex<inEnd-1)
        node->right=buildTree(inorder, postorder, rootIndex+1, inEnd, postStart+rootIndex-inStart, postEnd-1);
    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(!inorder.empty())
        return buildTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    return nullptr;
}
