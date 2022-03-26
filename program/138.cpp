#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

unordered_map<Node*, Node*> mp;

Node* copyList(Node* head) {
    Node* newNode = new Node(head->val);
    mp[head]=newNode;
    if(head->next) newNode->next = copyList(head->next);
    return newNode;
}

Node* copyRandomList(Node* head) {
    if(!head) return nullptr;
    Node* root = copyList(head);
    Node* newNode = root;
    while(newNode){
        if(head->random!=nullptr)
            newNode->random = mp[head->random];
        newNode=newNode->next, head=head->next;
    }
    return root;
}