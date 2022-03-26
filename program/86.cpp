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

// 设置两个头结点
ListNode* partition(ListNode* head, int x) {
    ListNode *smallHead=new ListNode(), *bigHead=new ListNode();
    ListNode *curNode=head, *curSmall=smallHead, *curBig=bigHead;
    while(curNode!=nullptr) {
        if(curNode->val<x) {
            curSmall->next=curNode;
            curSmall=curSmall->next;
        } else {
            curBig->next=curNode;
            curBig=curBig->next;
        }
        curNode=curNode->next;
    }
    curBig->next=nullptr; // 防止闭环
    curSmall->next=bigHead->next;
    return smallHead->next;
}