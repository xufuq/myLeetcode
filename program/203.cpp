

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 迭代求解，递归求解，官方题解中没有考虑删除不需要的节点的问题
// 虚拟头结点也会方便
ListNode* removeElements(ListNode* head, int val) {
    ListNode *current = head, *last = head;
    while (current != nullptr) {
        if(current->val == val){
            if (current==head) {
                last = current;
                current = current->next;
                delete head;
                head = current;
            }
            else{
                last->next = current->next;
                delete current;
                current = last->next;
            }
        }
        else{
            last = current;
            current= current->next;
        }
    }
    return head;
}

// 虚拟头结点
ListNode* removeElements1(ListNode* head, int val) {
    ListNode *newhead = new ListNode(0, head), *current = newhead;
    while(current->next!=nullptr){
        if(current->next->val==val)
            current->next = current->next->next;
        else
            current = current->next;
    }
    return newhead->next;
}