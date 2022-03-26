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

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> myQue;
    vector<vector<int>> result;
    vector<int> r;
    if(root!=nullptr) {
        myQue.push(root);
        myQue.push(nullptr);
    }
    while(!myQue.empty() && myQue.front()!=nullptr) {
        TreeNode* node = myQue.front();
        myQue.pop();
        if(node->left!=nullptr) myQue.push(node->left);
        if(node->right!=nullptr) myQue.push(node->right);
        r.push_back(node->val);
        if(myQue.front()==nullptr) {
            myQue.push(nullptr); 
            result.push_back(r);
            r.clear();
        }
    }
    return result;
}