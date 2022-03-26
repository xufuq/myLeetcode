#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};
// 层序遍历实现

void levelVisit(TreeNode *root){
    queue<TreeNode*> myQue;
    myQue.push(root);
    while(!myQue.empty()) {
        TreeNode *node = myQue.front();
        cout << node->val << " ";
        myQue.pop();
        if(node->left)  myQue.push(node->left);
        if(node->right) myQue.push(node->right);
    }
}

string serialize(TreeNode* root) {
    string result = "";
    queue<TreeNode*> myQue;
    myQue.push(root);
    while(!myQue.empty()) {
        TreeNode *node = myQue.front();
        myQue.pop();
        if(node){
            myQue.push(node->left);
            myQue.push(node->right);
            result += to_string(node->val)+" ";
        }
        else result += "null ";
    }
    int i=result.length()-1;
    for(;i>=0;--i){
        if(isdigit(result[i]))
            break;
    }
    result.erase(result.begin()+i+1, result.end());
    return result;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    istringstream stream(data);
    string str;
    queue<TreeNode*> myQue;
    TreeNode* root;
    if(stream >> str){ // 如果第一个能够正确读取到，那就一定是数字
        root=new TreeNode;
        root->val=stoi(str);
        myQue.push(root);
    }
    else return nullptr;
    while(stream >> str){
        TreeNode* node= myQue.front();
        myQue.pop();
        if(str!="null"){
            node->left=new TreeNode;
            node->left->val=stoi(str);
            myQue.push(node->left);
        }
        if(stream >> str){
            if(str!="null"){
                node->right=new TreeNode;
                node->right->val=stoi(str);
                myQue.push(node->right);
            }
        } else break;
    }
    return root;
}

int main(){
    string data = "1 2 3 null null 4 5";
    TreeNode* root = deserialize(data);
    levelVisit(root);
    string result=serialize(root);
    cout << result;
    return 0;
}