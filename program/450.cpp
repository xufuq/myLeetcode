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

// 非递归，考虑删除的节点有几个子树
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return nullptr;
    TreeNode* node =root, *pre=nullptr;
    // 先找到节点
    while(node && node->val!=key){
        pre=node;
        if(node->val > key)
            node=node->left;
        else
            node=node->right;
    }
    if(!node) return root; // 不存在key
    // 两个节点,固定在左子树找最大的节点
    if(node->left && node->right){
        pre=node;  // 如果node有子树，那么pre改为记录maxNode的父节点
        TreeNode* maxNode = node->left;
        while(maxNode->right){
            pre=maxNode;
            maxNode=maxNode->right;
        }
        node->val=maxNode->val;
        node=maxNode; // 这样就改为删除这个最大的节点，这个节点最多一个子节点，所以就和node剩下的情况结合在一起了
    }

    TreeNode *nextNode;
    if(node->left)
        nextNode=node->left;
    else
        nextNode=node->right;
    
    if(node==root) // 当前要删除的是root
        root=nextNode;
    else if(pre->left==node)
        pre->left=nextNode;
    else
        pre->right=nextNode;
    return root;

}

// 递归的方法
// 递归的意义不大，因为在有两个叶子节点的时候递归调用一次就够了
TreeNode* deleteNode(TreeNode* root, int key) {
    // 不是叶子节点的时候
}