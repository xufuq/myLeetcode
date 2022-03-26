#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 这个题目很重要，递归和迭代的做法
ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next==nullptr) return head; // 返回最后一个
    ListNode *newheader = reverseList(head->next);
    head->next->next=head;
    head->next = nullptr;
    return newheader;
}

ListNode* reverseList1(ListNode* head) {
    ListNode *current = head, *last = nullptr;
    while(head!=nullptr){
        current = head->next;
        head->next = last;
        last = head;
        head = current;
    }
    return last;
}