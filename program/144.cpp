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
void preorderTraversal(TreeNode* root, vector<int> &result) {
    result.push_back(root->val);
    if(root->left!=nullptr) preorderTraversal(root->left, result);
    if(root->right!=nullptr) preorderTraversal(root->right, result);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if(root!=nullptr)
        preorderTraversal(root, result);
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

// 前
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if(!root) return result;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        if(node->right!= nullptr) st.push(node->right);
        if(node->left!= nullptr) st.push(node->left);
    }
    return result;
}