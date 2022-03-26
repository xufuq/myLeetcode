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

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *preLeft, *leftNode, *rightNode, *preHead=new ListNode(0, head), *curNode=head, *preNode=preHead;
    int count=1;
    while(count<right) {
        if(count==left) {
            preLeft = preNode;
            leftNode=curNode;
            preNode=curNode;
            curNode=curNode->next;
        }
        else if(count>left && count<= right) {
            rightNode= curNode->next;
            curNode->next= preNode;
            preNode=curNode;
            curNode=rightNode;
            
        } else {
            preNode=curNode;
            curNode=curNode->next;
        }
        ++count;
    }
    rightNode=preNode;
    preLeft->next=rightNode;
    leftNode->next=curNode;
    return preHead->next;
}