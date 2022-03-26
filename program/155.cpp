#include <stack>
#include <vector>

using namespace std;

struct DLinkedNode {
    int value;
    DLinkedNode *prev, *next;
    DLinkedNode(): value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _value):value(_value), prev(nullptr), next(nullptr) {}
};

// 栈加双向链表
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        prev=new DLinkedNode(INT_MIN);
        tail=new DLinkedNode(INT_MAX);
        prev->next=tail;
        tail->prev=prev;
    }
    
    void push(int val) {
        DLinkedNode *node = new DLinkedNode(val);
        st.push(node);
        DLinkedNode *curNode=prev->next;
        while(curNode) { // 有tail，一定可以比较成功
            if(curNode->value >= val){ // 插在cur前面
                curNode->prev->next=node;
                node->prev=curNode->prev;
                curNode->prev=node;
                node->next=curNode;
                return;
            }
            curNode=curNode->next;
        }
    }
    
    void pop() {
        DLinkedNode *curNode=st.top();
        st.pop();
        curNode->prev->next = curNode->next;
        curNode->next->prev= curNode->prev;
    }
    
    int top() {
        return st.top()->value;
    }
    
    int getMin() {
        return prev->next->value;
    }
private: 
    DLinkedNode *prev, *tail;
    stack<DLinkedNode *> st;
};

// 官方题解
// 用一个辅助栈，存放当前已经产生的最小值