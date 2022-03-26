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

// 递归法
TreeNode* trimBST(TreeNode* root, int low, int high) {
    if(root == nullptr) return nullptr;
    // 需要释放空间，否则内存泄漏，程序不规范
    // 调试完成后再单独写一个释放内存的子函数
    if(root->val == low) root->left=nullptr;
    else if(root->val < low) return trimBST(root->right, low, high);
    else root->left=trimBST(root->left, low, high);

    if(root->val == high) root->right=nullptr;
    else if(root->val > high) return trimBST(root->left, low, high);
    else root->right=trimBST(root->right, low, high);
    return root;
}

// 迭代法
TreeNode* trimBST(TreeNode* root, int low, int high) {
    
}