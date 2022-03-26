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


// Encodes a tree to a single string.
// 用前序遍历，且不添加任何分割符,仅用逗号分割数字，仅根据大小比较完成
// 降低编码和解码的时间复杂度和空间复杂度
string serialize(TreeNode* root) {
    string result;
    if(root==nullptr) return result;
    result=to_string(root->val);
    if(root->left)  result+="," + serialize(root->left);
    if(root->right) result+="," + serialize(root->right);
    return result;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.empty()) return nullptr;
    cout << data << endl;
    // 不用递归，用迭代完成
    stringstream is(data);
    string str;
    getline(is, str, ',');
    int num=stoi(str);
    TreeNode *root=new TreeNode(num), *curNode=root;
    stack<TreeNode*> st;
    while(getline(is, str, ',')){
        int num=stoi(str);
        while(!st.empty() && num>st.top()->val) { // 找到当前所属分支
            curNode=st.top();
            st.pop();
        }
        TreeNode *pre=nullptr;
        while(curNode!=nullptr) {
            pre=curNode;
            if(num>curNode->val)
                curNode=curNode->right;
            else
                curNode=curNode->left;
            st.push(pre);
        }
        if(num<pre->val) {
            pre->left=new TreeNode(num);
            curNode=pre->left;
        }
        else {
            pre->right=new TreeNode(num);
            curNode=pre->right;
        }
    }
    return root;
}