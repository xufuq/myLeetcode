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

// 层序遍历
TreeNode* invertTree(TreeNode* root) {
    queue<TreeNode*> myQueue;
    if(root!=nullptr) myQueue.push(root);
    while(!myQueue.empty()) {
        TreeNode* node = myQueue.front();
        myQueue.pop();
        
        if(node->left!=nullptr) myQueue.push(node->left);
        if(node->right!=nullptr) myQueue.push(node->right);
    }
    return root;
}

// 中序遍历
void invertTree1(TreeNode* root) {
    swap(root->left, root->right);
    if(root->left!=nullptr) invertTree(root->left);
    if(root->right!=nullptr) invertTree(root->right);
}

TreeNode* invertTree(TreeNode* root) {
    if(root!=nullptr) {
        swap(root->left, root->right);
        if(root->left!=nullptr) invertTree(root->left);
        if(root->right!=nullptr) invertTree(root->right);
    }
    return root;
}