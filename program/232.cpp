#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        PushMode.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(PopMode.empty()){
            while(!PushMode.empty()){
                PopMode.push(PushMode.top());
                PushMode.pop();
            }
        }
        int x = PopMode.top();
        PopMode.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(PopMode.empty()){
            while(!PushMode.empty()){
                PopMode.push(PushMode.top());
                PushMode.pop();
            }
        }
        return PopMode.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return PopMode.size()+PushMode.size()==0?1:0;
    }

    stack<int> PushMode, PopMode;
};