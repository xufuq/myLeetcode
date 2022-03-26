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

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    ListNode *curNode = head;
    int len=0, count = 0;
    while (curNode != nullptr) {
        ++len;
        curNode=curNode->next;
    }
    vector<ListNode*> result;
    int aveLen=len/k;
    if(len%k>result.size()) ++aveLen;
    curNode=head;
    while(curNode!= nullptr) {
        ++count;
        if(count<aveLen)
            curNode=curNode->next;
        else { // 相等
            result.push_back(head);
            head=curNode->next;
            curNode->next=nullptr;
            curNode=head;
            count=0;
            aveLen=len/k;
            if(len%k>result.size()) ++aveLen;
        }
    }
    while(result.size()<k) 
        result.push_back(nullptr);
    return result;
}