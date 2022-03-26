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

// 采用迭代-堆栈实现
// 前中后序就是压入P和nullptr的位置不同
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    
    if(root!=nullptr) st.push(root);
    while(!st.empty()){
        TreeNode* p = st.top();
        if(p!=nullptr){
            st.pop();
            if(p->right!=nullptr) st.push(p->right);
            st.push(p);
            st.push(nullptr);
            if(p->left!=nullptr) st.push(p->left);
        }
        else{
            st.pop();
            p=st.top();
            st.pop();
            result.push_back(p->val);
        }
    }
    return result;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if(!root) return result;
    stack<TreeNode*> st;
    TreeNode* node=root;
    while(node || !st.empty()){
        if(node){
            st.push(node);
            node = node->left;
        }
        else{
            node = st.top();
            st.pop();
            result.push_back(node->val);
            node=node->right;
        }
    }
    return result;
}