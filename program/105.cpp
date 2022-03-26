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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStartIndex, int preEndIndex, int inStartIndex, int inEndIndex) {
    if(preStartIndex>=preEndIndex) return nullptr;
    TreeNode *root = new TreeNode(preorder[preStartIndex]);
    int curIndex=inStartIndex;
    while(inorder[curIndex]!=root->val) curIndex++;
    root->left=buildTree(preorder, inorder, preStartIndex+1, preStartIndex+curIndex-inStartIndex+1, inStartIndex, curIndex);
    root->right=buildTree(preorder, inorder, preStartIndex+curIndex-inStartIndex+1, preEndIndex, curIndex+1, inEndIndex);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
}