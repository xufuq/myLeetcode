#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
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

// 中遍历就可以了,左中右
// 找到大于后面的节点，说明这个节点不对
// 找到大于的节点，和后续最小的节点
// 迭代完成
void recoverTree(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode *first=nullptr, *second=nullptr, *cur=root, *pre=nullptr;
    while(!st.empty() || cur) {
        if(cur!=nullptr) {
            st.push(cur);
            cur=cur->left;
        }
        else {
            cur=st.top();
            st.pop();
            if(pre && first==nullptr && cur->val<pre->val) {
                first=pre;
                second=cur;
            }
            if(first!=nullptr && cur->val<second->val)
                second=cur;
            pre=cur;
            cur=cur->right;
        }
    }
    int temp=first->val;
    first->val=second->val;
    second->val=temp;
}