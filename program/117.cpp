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

void connect2(Node* root) {
    // 先右后左的顺序很重要
    if(root->right!=nullptr){
        Node* currentNode = root->next;
        while(currentNode != nullptr){
            if(currentNode->left!=nullptr){
                root->right->next=currentNode->left;
                break;
            }
            else if(currentNode->right!=nullptr){
                root->right->next=currentNode->right;
                break;
            }
            else
                currentNode=currentNode->next;
        }
        connect2(root->right);
    }
    if(root->left!=nullptr){
        Node* currentNode = root;
        if(root->right!=nullptr)
            root->left->next=root->right;
        else{
            currentNode =currentNode->next;
            while(currentNode != nullptr){
                if(currentNode->left!=nullptr){
                    root->left->next=currentNode->left;
                    break;
                } 
                else if(currentNode->right!=nullptr){
                    root->left->next=currentNode->right;
                    break;
                }
                else
                    currentNode=currentNode->next;
            }
        }
        connect2(root->left);
    }
    
}

Node* connect(Node* root) {
    if(root==nullptr) return root;
    connect2(root);
    return root;
}