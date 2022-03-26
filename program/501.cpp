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

vector<int> findMode(TreeNode* root) {
    vector<int> result;
    int currentNum = root->val, mostCount = 1, currentCount=0;
    TreeNode *node = root;
    stack<TreeNode*> st;
    while (!st.empty()) {
        if(node){
            st.push(node);
            node=node->left;
        }
        else{
            node = st.top();
            st.pop();
            if(node->val==currentNum) ++currentCount;
            else{ // 不相等，变更众数
                if(currentCount>mostCount)
                    result.clear();
                if(currentCount>=mostCount)
                    result.push_back(currentNum);
                currentNum=node->val;
                currentCount=1;
            }
        }
    } 
    return result;
}