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

// 必须是包含.的文件才计入长度
int lengthLongestPath(string input) {
    stack<int> path;
    int maxLength = 0, sIndex = 0;
    bool isFile=false;
    for(int i=0;i<input.length();) {
        if(input[i]=='.') {
            isFile=true;
        } else if(input[i]== '\n') {
            if(isFile) { // 当前遇到的是文件
                if(!path.empty())
                    maxLength=max(maxLength, path.top()+i-sIndex); 
                else
                    maxLength=max(maxLength, i-sIndex); 
                isFile=false;
            }
            else {
                if(!path.empty())
                    path.push(path.top()+i-sIndex+1);
                else
                    path.push(i-sIndex+1);
            }
            // 读取回车和制表符
            int countT=0;
            ++i;
            while(input[i]=='\t') {
                ++countT;
                ++i;
            }
            sIndex=i;
            while(countT<path.size()) 
                path.pop();
            continue;
        }
        ++i;
    }
    if(isFile) {
        if(!path.empty())
            maxLength=max(maxLength, path.top()+(int)input.length()-sIndex); 
        else
            maxLength=max(maxLength, (int)input.length()-sIndex); 
    }
    return maxLength;
}

int main() {
    string str="dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    cout << lengthLongestPath(str);
}