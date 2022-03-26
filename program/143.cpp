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
#include <time.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 先翻转后半部分的链表
void reorderList(ListNode* head) {
    // 先找到中间节点，快慢指针法
    // slow是最终的中间节点， 从这里开始翻转链表
    if(head==nullptr || head->next==nullptr) return;
    ListNode *slow=head, *fast=head, *pre=nullptr;
    while(fast!=nullptr) {
        pre=slow;
        slow=slow->next;
        fast=fast->next;
        if(fast)
            fast=fast->next;
    }
    // 前半截的链表把尾清零
    pre->next=nullptr;
    // 翻转后半部分列表
    pre=slow;
    slow=slow->next;
    pre->next=nullptr;
    while(slow) {
        fast=slow->next;
        slow->next=pre;
        pre=slow;
        slow=fast;
    }
    // 最终pre就是后半部分的从尾开始的头指针
    ListNode *left=head, *right=pre, *preHead=new ListNode();
    head=preHead;
    while(left) {
        head->next=left;
        head=head->next;
        left=left->next;
        head->next=right;
        head=head->next;
        if(right)
            right=right->next;
    }
    head=preHead->next;
}