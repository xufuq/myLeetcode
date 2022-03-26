#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 应该可以假设没有重复元素
// 链表二分法，时间复杂度不好
ListNode* insertionSortList(ListNode* head) {
    ListNode *preHead=new ListNode(0, head);
    ListNode *aHead = preHead->next, *aEnd=preHead->next; //aEnd可以取到
    ListNode *curNode = aHead->next, *nextNode=nullptr;
    aHead->next=nullptr;
    while(curNode) { // 还有未排序的点
        nextNode=curNode->next, curNode->next=nullptr;
        aHead = preHead->next, aEnd=nullptr;
        ListNode *slow=aHead, *fast=aHead;
        while(aHead->next!=aEnd){
            slow=aHead, fast=aHead;
            while(fast!=aEnd) { // 找到已排序的链表的二分点slow，查询是否可以插入
                fast=fast->next;
                if(fast!=aEnd) fast=fast->next;
                slow=slow->next;
            }
            if(slow->val > curNode->val)
                aEnd=slow;
            else
                aHead=slow;
        }
        if(aHead==preHead->next) { // 应该是头结点，否则没有这种情况
            if(aHead->val>curNode->val){
                curNode->next=preHead->next;
                preHead->next=curNode;
            } else {
                curNode->next=aHead->next;
                aHead->next=curNode;
            }
        } else {
            curNode->next=aEnd;
            aHead->next=curNode;
        }
        curNode=nextNode;
    }
    return preHead->next;
}

// 官方题解，从前往后找
ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* lastSorted = head;
    ListNode* curr = head->next;
    while (curr != nullptr) {
        if (lastSorted->val <= curr->val) {
            lastSorted = lastSorted->next;
        } else {
            ListNode *prev = dummyHead;
            while (prev->next->val <= curr->val) {
                prev = prev->next;
            }
            lastSorted->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
        }
        curr = lastSorted->next;
    }
    return dummyHead->next;
}
