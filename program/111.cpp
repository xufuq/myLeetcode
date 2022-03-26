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

int minDepth(TreeNode* root) {
    if(root!=nullptr){
        if(root->left!=nullptr&&root->right!=nullptr)
            return min(minDepth(root->left), minDepth(root->right))+1;
        else if(root->left!=nullptr)
            return minDepth(root->left)+1;
        else if(root->right!=nullptr)
            return minDepth(root->right)+1;
        else 
            return 1;
    }
    else
        return 0;
}

