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

ListNode* swapPairs(ListNode* head) {
    ListNode *preHead=new ListNode(0, head), *preNode=preHead;
    while(preNode->next && preNode->next->next) {
        ListNode *node=preNode->next, *nextPre=node->next->next;
        preNode->next=node->next;
        node->next->next=node;
        node->next=nextPre;
        preNode=nextPre;
    }
    return preHead->next;
}