#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include "math.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 利用快慢指针找到中间节点
// tail节点不在包含的范围内
TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
    if(head==tail) return nullptr;
    ListNode *slow=head, *fast=head;
    while(fast!=tail) {
        fast=fast->next;
        if(fast!=tail){
            fast=fast->next;
            slow=slow->next;
        }
    }
    TreeNode *result=new TreeNode(slow->val);
    result->left=sortedListToBST(head, slow);
    result->right=sortedListToBST(slow->next, tail);
    return result;
}

TreeNode* sortedListToBST(ListNode* head) {
    return sortedListToBST(head, nullptr);
}