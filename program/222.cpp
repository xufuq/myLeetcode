#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include "math.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool exist(TreeNode* root, int index, int level) {
    while(level--){
        if(index & 1<<level) root = root->right;
        else root = root->left;
    }
    return root?true:false;
}

int countNodes(TreeNode* root) {
    int level = 0;
    TreeNode *node=root;
    while (node!=nullptr) {
        ++level;
        node = node->left;
    }
    if(level<2) return level;
    int low = pow(2, level-1), high = pow(2, level)-1;
    while(low<high){
        int mid = (low + high)/2;
        bool mids = exist(root, mid, level-1);
        if(mids) low=mid+1;
        else high=mid-1;
    }
    if(exist(root, low, level-1)) return low;
    return low-1;
}

int main(){
    cout << pow(2,2) << endl;
}