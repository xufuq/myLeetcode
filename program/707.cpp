#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size=0;
        header = new ListNode(0, nullptr);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < size)
        {
            ListNode *current = header->next;
            for(int i=0; i<index; i++)
                current = current->next;
            return current->val;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        header->next = new ListNode(val, header->next);
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *current = header;
        for(int i=0; i<size; i++)
            current = current->next;
        current->next = new ListNode(val);
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size)
            return;
        ListNode *current = header;
        for(int i=0; i<index; i++)
            current = current->next;
        current->next = new ListNode(val, current->next);
        ++size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size)
            return;
        ListNode *current = header;
        for(int i=0; i<index; i++)
            current = current->next;
        current->next = current->next->next;
        --size;
    }

    int size;
    ListNode *header;
};

int main(){
    MyLinkedList *list = new MyLinkedList;
    list->addAtHead(1);
    list->addAtTail(3);
    list->addAtIndex(1,2);
    cout << list->get(1) << endl;
    list->deleteAtIndex(1);
    cout << list->get(1) << endl;
}