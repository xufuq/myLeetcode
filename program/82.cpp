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
    ListNode *preHead=new ListNode(0, head), *curNode=preHead;
    while(curNode->next!=nullptr) {
        if(curNode->next->next!=nullptr && curNode->next->val==curNode->next->next->val) {
            while(curNode->next->next!=nullptr && curNode->next->val==curNode->next->next->val) {
                curNode->next->next=curNode->next->next->next;
            }
            curNode->next=curNode->next->next;
        } else {
            curNode=curNode->next;
        }
    }
    return preHead->next;
}