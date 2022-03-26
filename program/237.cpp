struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void deleteNode(ListNode* node) {
    ListNode* next=node->next;
    while(next->next) {
        node->val=next->val;
        node=next;
        next=node->next;
    }
    node->val=next->val;
    delete next;
    node->next=nullptr;
}

void deleteNode(ListNode* node) {
    ListNode* next=node->next;
    node->val=next->val;
    node->next=next->next;
    delete next;
}