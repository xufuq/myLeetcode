#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool findNode(TreeNode* root, TreeNode* node){
    if(root==node) return true;
    else if(root->left && findNode(root->left, node)) return true;
    else if(root->right && findNode(root->right, node)) return true;
    else return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return nullptr;

    TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
    if(leftNode)
        return leftNode;

    TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);
    if(rightNode)
        return rightNode;

    if(findNode(root, p) && findNode(root, q))
        return root;
    return nullptr;
}

// 官方题解，更简单
// 主要就是如何判断是否有目标节点存在在当前分支的问题
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == q || root == p || root == NULL) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != NULL && right != NULL) return root;
    if (left == NULL) return right;
    return left;
}