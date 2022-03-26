struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    if(!head) return nullptr;
    ListNode *singualHead = head, *dualHead = head->next;
    ListNode *singCur=singualHead, *dualCur=dualHead;
    while(singCur->next && dualCur->next) {
        singCur->next=dualCur->next;
        singCur=singCur->next;
        dualCur->next=singCur->next;
        dualCur=dualCur->next;
    }
    singCur->next=dualHead;
    return singualHead;
}