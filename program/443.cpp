#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int compress(vector<char>& chars) {
    int currentIndex = 0, count = 1; // 当前可以被替代的内容起始位置
    char currentChar = chars[0];
    for(int i=1;i<chars.size();++i) {
        if(chars[i]==currentChar)
            ++count;
        else{
            chars[currentIndex] = currentChar;
            ++currentIndex;
            if(count != 1){
                string num = to_string(count);
                for(auto n : num){
                    chars[currentIndex] = n;
                    ++currentIndex;
                }
            }
            currentChar = chars[currentIndex];
        }
    }
}