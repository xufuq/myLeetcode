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


ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr) return nullptr;
    ListNode *curNode = head;
    unordered_set<int> visited;
    visited.insert(curNode->val);
    while(curNode->next != nullptr) {
        if(visited.count(curNode->next->val)==0) {
            visited.insert(curNode->next->val);
            curNode=curNode->next;
        } else {
            curNode->next=curNode->next->next;
        }
    }
    return head;
}