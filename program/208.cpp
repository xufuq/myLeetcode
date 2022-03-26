#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    string str;
    TreeNode *left, *right;
    TreeNode(string s) : str(s), left(nullptr), right(nullptr){}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=nullptr;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(root==nullptr) 
            root=new TreeNode(word);
        else {
            TreeNode *node = root, *pre=nullptr;
            while(node!=nullptr) {
                pre=node;
                if(node->str>word)
                    node=node->left;
                else 
                    node=node->right;
            }
            if(pre->str>word) pre->left=new TreeNode(word);
            else pre->right=new TreeNode(word);
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode *node=root;
        while(node){
            if(node->str==word) return true;
            else if(node->str>word) node=node->left;
            else node=node->right;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode *node=root;
        while(node){
            string str=node->str.substr(0, prefix.length());
            if(str==prefix) return true;
            else if(str>prefix) node=node->left;
            else node=node->right;
        }
        return false;
    }
private:
    TreeNode *root;
};

// 官方题解是每个包含26个子成员
// 按照字母一次往下找