struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *newheader = new ListNode(0, head);
    ListNode *fast = newheader, *slow = newheader;
    while(fast->next!=nullptr) {
        --n;
        if(n<0)
            slow = slow->next;
        fast = fast->next;
    }
    slow = slow->next->next;
    return newheader->next;
}