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
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// 一个set，一个queue进行广度优先查询
Node* cloneGraph(Node* node) {
    if(node==nullptr) return nullptr;
    unordered_map<int, Node*> visitedNum;
    queue<vector<Node*>> nodes;
    Node *head=new Node(node->val), *cur=head;
    visitedNum[node->val]=cur;
    nodes.push({node, cur});
    while(!nodes.empty()) {
        node=nodes.front()[0];
        cur=nodes.front()[1];
        nodes.pop();
        for(auto neib:node->neighbors) {
            if(visitedNum.count(neib->val)) { // 已经存在这个元素
                cur->neighbors.push_back(visitedNum[neib->val]);
            }
            else { // 不存在这个元素
                cur->neighbors.push_back(new Node(neib->val));
                visitedNum[neib->val]=cur->neighbors.back();
                nodes.push({neib, cur->neighbors.back()});
            }
        }
    }
    return head;
}