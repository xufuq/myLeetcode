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


TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *cur=root, *pre=nullptr;
        while(cur || !st.empty()){
            if(cur){
                st.push(cur);
                cur=cur->right;
            }
            else{
                cur=st.top();
                st.pop();
                if(pre) cur->val=cur->val+pre->val;
                pre=cur;
                cur=cur->left;
            }
        }
        return root;
    }