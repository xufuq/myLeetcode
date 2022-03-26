#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct Node {
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) {
    queue<Node*> myQue;
    vector<vector<int>> result;
    vector<int> r;
    if(root!=nullptr) {
        myQue.push(root);
        myQue.push(nullptr);
    }
    while(!myQue.empty() && myQue.front()!=nullptr) {
        Node* node = myQue.front();
        myQue.pop();
        for(auto c : node->children) myQue.push(c);
        r.push_back(node->val);
        if(myQue.front()==nullptr) {
            myQue.pop();
            myQue.push(nullptr); 
            result.push_back(r);
            r.clear();
        }
    }
    return result;
}