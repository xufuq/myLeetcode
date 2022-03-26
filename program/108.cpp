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

TreeNode* sortedArrayToBST(vector<int>& nums, int startIndex, int endIndex) {
    if(startIndex >= endIndex) return nullptr;
    int midIndex = (startIndex + endIndex)/2;
    TreeNode *root = new TreeNode(nums[midIndex]);
    root->left = sortedArrayToBST(nums, startIndex, midIndex);
    root->right = sortedArrayToBST(nums, midIndex+1, endIndex);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size());
}