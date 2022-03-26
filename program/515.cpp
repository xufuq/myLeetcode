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

vector<int> largestValues(TreeNode* root) {
    queue<TreeNode*> myQue;
    vector<int> result;
    int index = 0;
    if(root!=nullptr) {
        myQue.push(root);
        myQue.push(nullptr);
        result.push_back(INT32_MIN);
    }
    while(!myQue.empty() && myQue.front()!=nullptr) {
        TreeNode* node = myQue.front();
        myQue.pop();
        if(node->left!=nullptr) myQue.push(node->left);
        if(node->right!=nullptr) myQue.push(node->right);
        if(node->val > result[index]) result[index] = node->val;
        if(myQue.front()==nullptr) {
            myQue.pop();
            if(myQue.empty())
                break;
            myQue.push(nullptr); 
            result.push_back(INT32_MIN);
            ++index;
        }
    }
    return result;
}