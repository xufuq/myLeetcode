#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    int count = 0;
    stack<int> st;
    ListNode *faster = head;
    while(faster != nullptr) {
        faster = faster->next;
        if(faster)
            faster=faster->next;
        else{
            st.push(head->val);
            break;
        }
        st.push(head->val);
        head = head->next;
    }
    head=head->next;
    while(head != nullptr) {
        if(st.top() != head->val) return false;
        st.pop();
        head = head->next;
    }
    return true;
}
// 直接两个指针对比
bool isPalindrome(ListNode* head) {
    ListNode *faster = head, *slow= head, *pre=nullptr, *temp=nullptr;
    while(faster != nullptr) {
        faster = faster->next;
        if(faster)
            faster=faster->next;
        else{
            slow=slow->next;
            break;
        }
        temp=slow->next;
        slow->next=pre;
        pre=slow;
        slow=temp;
    }
    while(slow != nullptr) {
        if(pre->val!=slow->val) return false;
        pre = pre->next;
        slow = slow->next;
    }
    return true;
}