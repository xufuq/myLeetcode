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

// 和标准题解一模一样
// 不过可以把递归在简化
int getCount(TreeNode* root) {
    if(root->left == nullptr && root->right == nullptr) return 0;
    int cameraCount = 0;
    if(root->left){ // 左节点存在
        cameraCount += getCount(root->left);
        if(root->left->val==0){
            root->val=2;
            root->left->val=1;
            ++cameraCount;
        }
        else if(root->left->val==2  && root->val==0){ // val为1的时候不用管
            root->val=1;
        }
    }
    if(root->right){ // 右节点存在
        cameraCount += getCount(root->right);
        if(root->right->val==0){
            if(root->val==2) root->right->val=1;
            else {
                root->val=2;
                root->right->val=1;
                ++cameraCount;
            }
        }
        else if(root->right->val==2 && root->val==0)
            root->val=1;
    }
    return cameraCount;
}


int getCount(TreeNode* root) {
    if(!root) return 0;
    int cameraCount = 0;
    cameraCount += getCount(root->left);
    cameraCount += getCount(root->right);

    if((root->left&&root->left->val==0) || (root->right&&root->right->val==0)){
        root->val=2;
        ++cameraCount;
    }
    else if((root->left&&root->left->val==2) || (root->right&&root->right->val==2))
        root->val=1;
    return cameraCount;
}

// 从叶子节点向根节点放
int minCameraCover(TreeNode* root) {
    int result = getCount(root);
    if(root->val==0) ++result;
    return max(result, 1);
}