#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <stack>
#include <numeric>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    bool exist;
    vector<Node *> children;
    Node() {exist = false; children=vector<Node*>(26); }
};

// 利用字典树实现
class WordDictionary {
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        bool exist;
        Node *cur=root;
        for(auto &c:word) { // 只有普通字符串
            if(cur->children[c-'a']==nullptr) 
                cur->children[c-'a']=new Node;
            cur=cur->children[c-'a'];
        }
        cur->exist=true;
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }

private:
    bool search(string &word, int index, Node *root_){
        Node *cur=root_;
        for(int i=index;i<word.length();++i) {
            if(isalpha(word[i])) {
                if(cur->children[word[i]-'a']==nullptr) 
                    return false;
                cur=cur->children[word[i]-'a'];
            }
            else { // 使用替代的做法
                for(int k=0;k<26;++k) {
                    if(cur->children[k] && search(word, i+1, cur->children[k]))
                        return true;
                }
                return false;
            }
        }
        return cur->exist;
    }
    Node *root;
};
