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

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// 用迭代法完成
// 前序遍历翻转，中右左
vector<int> postorder(Node* root) {
    vector<int> result;
    if(root==nullptr) return result;
    stack<Node*> st;
    st.push(root);
    Node *curr;
    while(!st.empty()) {
        curr=st.top();
        st.pop();
        if(!curr->children.empty()) { // 有子节点
            for(auto it=curr->children.begin();it!=curr->children.end();++it)
                st.push(*it);
        }
        result.push_back(curr->val);
    }
    reverse(result.begin(), result.end());
    return result;
}