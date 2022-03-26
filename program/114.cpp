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

void flatten(TreeNode* root) {
    if(!root) return;
    stack<TreeNode*> myQue;
    myQue.push(root);
    TreeNode *preNode=new TreeNode(-1);
    root=preNode;
    while(!myQue.empty()) {
        TreeNode *node = myQue.top();
        myQue.pop();
        preNode->right = node;
        preNode->left = nullptr;
        if(node->right!=nullptr) myQue.push(node->right);
        if(node->left!=nullptr) myQue.push(node->left);
    }
    root=root->right;
}