#include <map>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode *fast=head, *slow = head;
    --k;
    while(fast->next){
        if(k>0){
            fast = fast->next;
            --k;
        } else {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}