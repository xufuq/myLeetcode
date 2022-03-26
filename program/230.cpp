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

// 中序遍历
// 用一个变量记录当前是第几个节点
int kthSmallest(TreeNode* root, int k) {
    TreeNode *cur = root;
    stack<TreeNode*> st;
    st.push(root);
    int count=0;
    while(cur!=nullptr || !st.empty()) {
        cur=st.top();
        st.pop();
        if(cur!=nullptr) {
            st.push(cur->right);
            st.push(cur);
            st.push(cur->left);
        } 
        else {
            cur=st.top();
            st.pop();
            ++count;
            if(count==k) return cur->val;
        }
    }
    return 0;
}