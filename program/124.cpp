#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int result=INT32_MIN;

// 官方题解的答案是在求左右分支时判断其与零的关系
// 通过求max函数实现
// 只有当左右贡献度大于0时才选用
int getLeavePath(TreeNode *root){
    if(root->left==nullptr && root->right==nullptr) {
        result = max(result, root->val);
        return root->val;
    }
    else if(root->left!=nullptr && root->right==nullptr){
        int leftSum=getLeavePath(root->left); 
        result = max({result, root->val, root->val+leftSum, leftSum});
        return max(leftSum+root->val, root->val);
    }
    else if(root->left==nullptr && root->right!=nullptr){
        int rightSum=getLeavePath(root->right);
        result = max({result, root->val, root->val+rightSum, rightSum});
        return max(rightSum+root->val, root->val);
    }
    // 两个都有值
    int leftSum=getLeavePath(root->left);
    int rightSum=getLeavePath(root->right);
    if(root->val<=0) result=max({result, root->val, leftSum, rightSum, leftSum+rightSum+root->val});
    else result=max({result, root->val, leftSum+root->val, rightSum+root->val, leftSum+rightSum+root->val});
    return max({leftSum+root->val, rightSum+root->val, root->val});
}

int maxPathSum(TreeNode* root) {
    getLeavePath(root);
    return result;
}

int maxSum = INT_MIN;
// 官方题解
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int priceNewpath = node->val + leftGain + rightGain;

        // 更新答案
        maxSum = max(maxSum, priceNewpath);

        // 返回节点的最大贡献值
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
