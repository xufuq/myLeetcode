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

// 用迭代法完场
// 前序遍历 中左右
vector<int> preorder(Node* root) {
    vector<int> result;
    if(root==nullptr) return result;
    stack<Node*> st;
    st.push(root);
    Node *curNode=nullptr;
    while(!st.empty()) {
        curNode=st.top();
        st.pop();
        if(curNode) {
            result.push_back(curNode->val);
            for(auto it=curNode->children.rbegin(); it!=curNode->children.rend();++it) 
                st.push(*it);
        }
    }
    return result;
}