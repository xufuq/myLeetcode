#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <stack>
using namespace std;



// 时间复杂度过高
// bool isValid(vector<vector<char>>& board, int x, int y, string &word, int strIndex) {
//     if(strIndex==word.length()) return true;
//     if(x>=0 && y>=0 && x<board.size() && y<board[0].size() && board[x][y]==word[strIndex]) { // 当前字符匹配
//         board[x][y]=' ';
//         if(isValid(board, x, y+1, word, strIndex+1) || isValid(board, x, y-1, word, strIndex+1) || 
//             isValid(board, x+1, y, word, strIndex+1) || isValid(board, x-1, y, word, strIndex+1)) {
//             board[x][y]=word[strIndex];
//             return true;
//         }
//         board[x][y]=word[strIndex];
//     }
//     return false;
// }

// vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//     vector<string> result;
//     for(auto &word : words) {
//         for(int i=0;i<board.size();++i){
//             int len=result.size();
//             for(int j=0;j<board[0].size();++j){
//                 if(isValid(board, i, j, word, 0)){
//                     result.push_back(word);
//                     break;
//                 }
//             }
//             if(result.size()>len) break;
//         }
//     }
//     return result;
// }


struct DictNode {
    bool isWord; //是否是一个完整的单词
    DictNode *next[26]={NULL}; // 指针数组

    DictNode(bool isword) : isWord(isword) {}
};

// 通过寻找相同前缀来降低时间复杂度
bool isValid(vector<vector<char>>& board, int x, int y, DictNode *root[], string &path, vector<string> &result) {
    if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]==' ') return false;
    
    int curIndex=board[x][y]-'a';
    
    if(root[curIndex]) { // 当前单词(路径)是否有效
        path.push_back(board[x][y]);
        board[x][y]=' '; // 把当前走过的点设置为空
        if(root[curIndex]->isWord){
            result.push_back(path);
            root[curIndex]->isWord=false; // 避免重复搜索
        }
        if(isValid(board, x, y+1, root[curIndex]->next, path, result) || isValid(board, x, y-1, root[curIndex]->next, path, result) || 
            isValid(board, x+1, y, root[curIndex]->next, path, result) || isValid(board, x-1, y, root[curIndex]->next, path, result)) {
            delete root[curIndex];
            root[curIndex]=nullptr;
        }
        board[x][y]=path.back();
        path.pop_back();
    }

    for(int i=0;i<26;++i) { // 子节点全部为空时返回true，即在当前节点下的所有单词都搜索完了
        if(root[i]!=nullptr) 
            return false;
    }
    return true;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> result;
    int wordCount=words.size();
    // 创建一个表记录每一对单词之间重复的字符数
    // 这样可以节省相同前缀遍历时间
    // 创建一个子节点有26个点的字典树
    DictNode *root=new DictNode(false);
    for(auto word : words) {
        DictNode *cur=root;
        for(auto &c : word) {
            if(cur->next[c-'a']==nullptr)
                cur->next[c-'a']=new DictNode(false);
            cur=cur->next[c-'a'];
        }
        cur->isWord=true;
    }
    string path;
    for(int i=0;i<board.size();++i){
        for(int j=0;j<board[0].size();++j){
            if(isValid(board, i, j, root->next, path, result)){
                delete root;
                root=nullptr;
                return result;
            }
        }
    }
    return result;
}

int main() {

}