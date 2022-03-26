#include <map>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 先分别获得长度
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA=0, lenB=0;
    ListNode *curA=headA, *curB=headB;
    while(curA!=nullptr){
        curA = curA->next;
        ++lenA;
    }
    while(curB!=nullptr){
        curB = curB->next;
        ++lenB;
    }
    curA=headA, curB=headB;
    while(lenA>0){
        if(lenA>lenB){
            curA=curA->next;
            --lenA;
        }
        else if(lenB>lenA){
            curB=curB->next;
            --lenB;
        }
        else {
            if(curA==curB) return curB;
            curA=curA->next, curB=curB->next;
            --lenA, --lenB;
        }
    }
    return nullptr;
}