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


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *preNode=nullptr, *curNode=l1;
    while(curNode!=nullptr) {
        ListNode *temp=curNode->next;
        curNode->next=preNode;
        preNode=curNode;
        curNode=temp;
    }
    l1=preNode;
    preNode=nullptr, curNode=l2;
    while(curNode!=nullptr) {
        ListNode *temp=curNode->next;
        curNode->next=preNode;
        preNode=curNode;
        curNode=temp;
    }
    l2=preNode;
    int getIn=0;
    ListNode *preHead=new ListNode;
    curNode=preHead;
    while(l1!=nullptr && l2!=nullptr) {
        curNode->next=new ListNode((l1->val+l2->val+getIn)%10);
        getIn=(l1->val+l2->val+getIn)/10;
        l1=l1->next, l2=l2->next;
        curNode=curNode->next;
    }
    ListNode *longList=l1==nullptr?l2:l1;
    while(longList!=nullptr) {
        int val=(longList->val+getIn)%10;
        getIn=(longList->val+getIn)/10;
        curNode->next=new ListNode(val);
        curNode=curNode->next;
        longList=longList->next;
    }
    if(getIn) {
        curNode->next=new ListNode(getIn);
        curNode=curNode->next;
    }
    preNode=nullptr, curNode=preHead->next;
    while(curNode!=nullptr) {
        ListNode *temp=curNode->next;
        curNode->next=preNode;
        preNode=curNode;
        curNode=temp;
    }
    preHead->next=preNode;
    return preHead->next;
}