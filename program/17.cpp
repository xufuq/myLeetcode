#include <vector>
#include <string>

using namespace std;

vector<string> enCode={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> result;

// index代表当前是第几个字符

void letterCombinations(string digits, int index, string &combine){
    if(index==digits.length()){
        result.push_back(combine);
        return;
    }
    int enCodeIndex = digits[index]-'2';
    for(auto &c : enCode[enCodeIndex]) {
        combine.push_back(c);
        letterCombinations(digits, index+1, combine);
        combine.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if(!digits.empty()){
        string combine;
        letterCombinations(digits, 0, combine);
    }
    return result;
}  