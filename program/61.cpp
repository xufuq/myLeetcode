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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    stack<ListNode*> st;
    ListNode *curNode=head;
    while(curNode) {
        st.push(curNode);
        curNode=curNode->next;
    }
    k=k%st.size();
    while(k>0) {
        st.top()->next=head;
        head=st.top();
        st.pop();
    }
    st.top()->next=nullptr;
    return head;
}