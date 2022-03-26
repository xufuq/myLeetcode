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
    Node* prev;
    Node* next;
    Node* child;
};

Node* flatten(Node* head) {
    stack<Node*> st;
    Node *curNode=head, *preNode=nullptr;
    while(curNode!=nullptr || !st.empty()) {
        if(curNode==nullptr) {
            curNode=st.top();
            st.pop();
            curNode->prev=preNode;
            preNode->next=curNode;
        }
        else if(curNode->child!=nullptr) {
            st.push(curNode->next);
            curNode->child->prev=curNode;
            curNode->next=curNode->child;
            curNode->child=nullptr;
        } 
        else {
            preNode=curNode;
            curNode = curNode->next;
        }
    }
    return head;
}