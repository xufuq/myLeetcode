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

// 不考虑空间限制
ListNode* sortList(ListNode* head) {
    multiset<int> nums;
    ListNode *curNode = head;
    while (curNode != nullptr){
        nums.insert(curNode->val);
        curNode=curNode->next;
    }
    curNode=head;
    for(auto it=nums.begin(); it != nums.end();++it){
        curNode->val=*it;
        curNode=curNode->next;
    }
    return head;
}

// 自底向上递归方法
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    else if(!l2) return l1;

    ListNode *result, *current = new ListNode(-1);
    result=current;
    while(l1 && l2) { // 其中一个为空后就不用合并了
        if(!l1 || (l2 && l1->val >= l2->val)){
            current->next=l2;
            l2=l2->next;
            current=current->next;
        } else {
            current->next=l1;
            l1=l1->next;
            current=current->next;
        }
    }
    current->next = l1==nullptr?l2:l1;
    return result->next;
}

ListNode* sortList(ListNode* head) {
    ListNode *prev = new ListNode(0, head), *cur=prev;
    int len=0;
    while(cur->next!=nullptr){
        cur=cur->next;
        ++len;
    }
    int subLen=1;
    cur=prev->next;
    while(subLen<len){
        ListNode *preHead=prev, *cur=preHead->next;
        while(cur!=nullptr){
            ListNode *first = cur;
            for(int i=1;i<subLen && cur->next!=nullptr;++i)
                cur=cur->next;
            ListNode *second = cur->next;
            cur->next=nullptr;
            cur=second;
            for(int i=1;i<subLen  && cur!=nullptr;++i)
                cur=cur->next;

            ListNode *next= nullptr;
            if(cur!=nullptr){
                next=cur->next;
                cur->next=nullptr;
            }
            ListNode *merge=mergeTwoLists(first, second);
            preHead->next=merge;
            while(preHead->next!=nullptr)
                preHead=preHead->next;
            cur=next;
        }
        subLen*=2;
    }
    return prev->next;
}