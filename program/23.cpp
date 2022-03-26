#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeLists(ListNode* left, ListNode* right) {
    ListNode *preHead = new ListNode(-1), *currentNode = preHead;
    while(left && right) {
        if(left->val < right->val){
            currentNode->next=left;
            left=left->next;
        } else {
            currentNode->next=right;
            right=right->next;
        }
        currentNode = currentNode->next;
    }
    currentNode->next= left==nullptr?right:left;
    return preHead->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) return nullptr;
    ListNode *result = lists[0];
    for(int i=1;i<lists.size();++i)
        result = mergeLists(result, lists[i]);
    
    return result;
}

// 还可以采用分治的方法， 这样可以减少每一次合并时的长度
// 需要额外写两个函数，一个用来合并两个以上，一个用来合并两个
