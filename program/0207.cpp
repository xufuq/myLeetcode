#include <map>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 先遍历获得两个链表的长度，然后长的一个缩进以保持长度相同，然后逐个对比是否相等。
// 这里没有再进行详细解了，递归失败，时间复杂度过高
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==headB) return headA;
    ListNode *first = nullptr, *second = nullptr;
    if(headA==nullptr || headB==nullptr)
        return nullptr;
    else{
        first = getIntersectionNode(headA->next, headB);
        second = getIntersectionNode(headA, headB->next);
        if(first==nullptr)
            return second;
        else if(second==nullptr)
            return first;
        else if(first->next == second)
            return first;
        else
            return second;
    }
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==nullptr || headB==nullptr) return nullptr;
    int lenA=0, lenB=0;
    ListNode *hA=headA, *hB=headB;
    while(hA!=nullptr) {
        ++lenA;
        hA=hA->next;
    }
    while(hB!=nullptr) {
        ++lenB;
        hB=hB->next;
    }
    hA=headA, hB=headB;
    while(lenA>lenB) {
        hA=hA->next;
        --lenA;
    }
    while(lenA<lenB) {
        hB=hB->next;;
        --lenB;
    }
    while(hA!=hB) {
        hA=hA->next;
        hB=hB->next;
    }
    return hB;
}