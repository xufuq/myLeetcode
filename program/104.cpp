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

// 递归做，当然用层序遍历数队列也可以
// 动态规划的思想

int maxDepth(TreeNode* root) {
    if(root!=nullptr)
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    else
        return 0;
}