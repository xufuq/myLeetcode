#include <string>
#include <iostream>

using namespace std;

string reverseWords(string s){
    string result;
    auto wordBegin=s.begin(), wordEnd=wordBegin;
    while(wordEnd!=s.end()){
        while(*wordBegin==' ') {
            ++wordBegin;
            if(wordBegin==s.end())
                return result;
        }
        wordEnd=wordBegin;
        while(wordEnd!=s.end() && *wordEnd!=' ') ++wordEnd;
        result = string(wordBegin, wordEnd) + " " + result;
        wordBegin=wordEnd;
    }
    result.erase(result.length()-2);
    return result;
}

int main(){
    string s = "  hello world  ";
    cout << reverseWords(s);
}