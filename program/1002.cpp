#include <unordered_map>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> commonChars(vector<string>& words) {
    vector<multiset<char>> iset;
    for(auto str : words) {
        multiset<char> cset(str.begin(), str.end());
        iset.push_back(cset);
        for(auto it = cset.begin(); it != cset.end();++it)
            cout << *it << " ";
        cout << endl;
    }
    vector<string> result;
    for(char word = 'a'; word <= 'z'; word++) {
        int i=INT16_MAX;
        for(auto cset : iset) {
            int num = cset.count(word);
            i = i < num ? i : num;
        }
        string str;
        str.push_back(word);
        cout << str << endl;
        while(i--)
            result.push_back(str);
    }
    return result;
}

vector<string> commonChars(vector<string>& words) {
    vector<unordered_map<char, int>> wordCount;
    for(auto str : words) {
        unordered_map<char, int> word;
        for(auto c : str)
            ++word[c];
        wordCount.push_back(word);
    }
    vector<string> result;
    for(auto it = wordCount[0].begin(); it != wordCount[0].end();++it){
        for(int i=1;i<wordCount.size();++i){
            int nowWordCount = wordCount[i][it->first];
            if(nowWordCount==0){
                it->second =0;
                break;
            }
            else
                it->second = it->second < nowWordCount?it->second:nowWordCount;
        }

        while(it->second--)
            result.push_back(string(1,it->first));
    }
}

// 用两个26长度的数组记录最小和当前，然后每访问一个word就将连个数组进行一次比较++
vector<string> commonChars(vector<string>& words) {

}

int main(){
    vector<string> words = {"bella","label","roller"};
    vector<string> result = commonChars(words);
}