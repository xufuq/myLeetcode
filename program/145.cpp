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

// 递归实现
void postorderTraversal(TreeNode* root, vector<int> &result) {
    if(root->left!=nullptr) postorderTraversal(root->left, result);
    if(root->right!=nullptr) postorderTraversal(root->right);
    result.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if(root!=nullptr)
        postorderTraversal(root, result);
    return result;
}

// 迭代实现
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if(root != nullptr)
        st.push(root);
    while(!st.empty()) {
        TreeNode* tr = st.top();
        st.pop();
        result.push_back(tr->val);
        if(tr->right != nullptr) st.push(tr->right);
        if(tr->left != nullptr) st.push(tr->left);
    }
    return result;
}