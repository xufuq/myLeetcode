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

ListNode* reverseKGroup(ListNode* head, int k) {
    if(k==0) return head;
    int count=0;
    ListNode *preHead=new ListNode(0, head), *preNode=preHead, *curNode=preHead->next;
    while(curNode) {
        ++count;
        curNode=curNode->next;
        if(count==k) { // 达到了指定数目
            ListNode *pre=preNode->next, *cur=pre->next, *next;
            --count;
            while(count>0) {
                next=cur->next;
                cur->next=pre;
                pre=cur;
                cur=next;
                --count;
            }
            preNode->next->next=curNode;
            cur=preNode->next;
            preNode->next=pre;
            preNode=cur;
        }
    }
    return preHead->next;
}