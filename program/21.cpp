struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    else if(!l2) return l1;

    ListNode *result, *current;
    if(l1->val < l2->val){
        current = l1;
        l1=l1->next;
    } else {
        current = l2;
        l2=l2->next;
    }
    result = current;
    while(l1 || l2) { // 其中一个为空后就不用合并了
        if(!l1 || (l2 && l1->val >= l2->val)){
            current->next=l2;
            l2=l2->next;
            current=current->next;
        } else {
            current->next=l1;
            l1=l1->next;
            current=current->next;
        }
    }
    return result;
}

// 官方优化
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    else if(!l2) return l1;

    ListNode *result, *current = new ListNode(-1);
    result=current;
    while(l1 && l2) { // 其中一个为空后就不用合并了
        if(!l1 || (l2 && l1->val >= l2->val)){
            current->next=l2;
            l2=l2->next;
            current=current->next;
        } else {
            current->next=l1;
            l1=l1->next;
            current=current->next;
        }
    }
    current->next = l1==nullptr?l2:l1;
    return result->next;
}