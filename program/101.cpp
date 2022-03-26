#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode* leftNode, TreeNode* rightNode) {
    bool leftr, rightr;
    if(leftNode->val!=rightNode->val)
        return false;

    if(leftNode->left!=nullptr && rightNode->right!=nullptr)
        leftr = isSymmetric(leftNode->left, rightNode->right);
    else if(leftNode->left==nullptr && rightNode->right==nullptr)
        leftr = true;
    else
        return false;
    if(leftr==false)
        return false;
    
    // 还有一半没写
    if(leftNode->right!=nullptr && rightNode->left!=nullptr)
        rightr = isSymmetric(leftNode->right, rightNode->left);
    else if(leftNode->right==nullptr && rightNode->left==nullptr)
        rightr = true;
    else 
        rightr=false;
    return rightr;
}

// 递归解法简化
bool isSymmetric(TreeNode* leftNode, TreeNode* rightNode) {
    if(!leftNode && !rightNode) return true;
    if(!leftNode || !rightNode) return false;
    return (leftNode->val==rightNode->val) && isSymmetric(leftNode->left, rightNode->right) && 
            isSymmetric(leftNode->right, rightNode->left);;
}

bool isSymmetric(TreeNode* root) {
    return isSymmetric(root, root);
}

// 迭代解法
bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> myQueue;
    myQueue.push(root);
    myQueue.push(root);
    while(!myQueue.empty()){
        TreeNode* a = myQueue.front();
        myQueue.pop();
        TreeNode* b = myQueue.front();
        myQueue.pop();
        if(!a && !b) continue;
        if(!a || !b) return false;
        if(a->val!=b->val) return false;
        myQueue.push(a->left);
        myQueue.push(b->right);

        myQueue.push(a->right);
        myQueue.push(b->left);
    }
    return true;
}