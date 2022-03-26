#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect1(Node* root) {
    queue<Node*> myQue;
    if(root!=nullptr) {
        myQue.push(root);
        myQue.push(nullptr);
    }
    while(!myQue.empty() && myQue.front()!=nullptr) {
        Node* node = myQue.front();
        myQue.pop();
        node->next=myQue.front();
        if(node->left!=nullptr) myQue.push(node->left);
        if(node->right!=nullptr) myQue.push(node->right);
        if(myQue.front()==nullptr) {
            myQue.pop();
            if(myQue.empty())
                break;
            myQue.push(nullptr); 
        }
    }
    return root;
}

void connect2(Node* root) {
    if(root->left!=nullptr){
        root->left->next=root->right;
        connect2(root->left);
        root->right->next=root->next==nullptr?nullptr:root->next->left;
        connect2(root->right);
    }
}

Node* connect(Node* root) {
    if(root==nullptr) return root;
    connect2(root);
    return root;
}