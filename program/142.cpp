#include "set"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
    set<ListNode *> nodes ;
    while (head!=nullptr) {
        if(nodes.find(head) == nodes.end())
            nodes.insert(head);
        else
            return head;
    }
    return nullptr;
}

ListNode *detectCycle2(ListNode *head) {
    ListNode *slow = head, *fast=head;
    while(fast!=nullptr){
        if(fast->next!=nullptr)
            fast = fast->next->next;
        else
            return nullptr;
        slow = slow->next;
        if(slow == fast){
            while(slow!=head){
                slow = slow->next;
                head = head->next;
            }
            return slow;
        }
    }
}