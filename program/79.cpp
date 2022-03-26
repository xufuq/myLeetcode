#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <map>

using namespace std;

// 可行，但时间复杂度高
// 我感觉标准答案的递归回溯和这个的方法一样啊
bool exist(vector<vector<char>>& board, string word) {
    stack<vector<int>> toUseSt, usedSt;
    int row = board.size(), col = board[0].size();
    vector<vector<bool>> usedVec(row, vector<bool>(col, false));
    // toUseSt.push({-1,-1});
    cout << row << " " << col;
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(board[i][j] == word[0])
                toUseSt.push({i, j});
        }
    }

    int curIndex=0;
    while(!toUseSt.empty()) {
        vector<int> curPoint=toUseSt.top();
        toUseSt.pop();
        if(curPoint[0]==-1){
            --curIndex;
            usedVec[usedSt.top()[0]][usedSt.top()[1]]=false;
            usedSt.pop();
        } else {
            curIndex++;
            usedSt.push(curPoint);
            usedVec[curPoint[0]][curPoint[1]]=true;
            if(curIndex==word.size()) return true;
            toUseSt.push({-1, -1});
            // 找四个方向的坐标
            if(curPoint[0]-1>=0 && !usedVec[curPoint[0]-1][curPoint[1]] && board[curPoint[0]-1][curPoint[1]]==word[curIndex])
                toUseSt.push({curPoint[0]-1, curPoint[1]});
            if(curPoint[0]+1<row && !usedVec[curPoint[0]+1][curPoint[1]] && board[curPoint[0]+1][curPoint[1]]==word[curIndex])
                toUseSt.push({curPoint[0]+1, curPoint[1]});
            if(curPoint[1]-1>=0 && !usedVec[curPoint[0]][curPoint[1]-1] && board[curPoint[0]][curPoint[1]-1]==word[curIndex])
                toUseSt.push({curPoint[0], curPoint[1]-1});
            if(curPoint[1]+1 < col && !usedVec[curPoint[0]][curPoint[1]+1] && board[curPoint[0]][curPoint[1]+1]==word[curIndex])
                toUseSt.push({curPoint[0], curPoint[1]+1});
        }
    }
    return false;
}

// 答案的递归解法，感觉并不比
// 递归，不知道为什么时间复杂度比我的迭代低
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        if (board[i][j] != s[k]) {
            return false;
        } else if (k == s.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }