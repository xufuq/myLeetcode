#include <string>
#include <iostream>

using namespace std;

string reverseStr(string s, int k) {
    int index;
    for(index = 0; index+k-1 < s.length();index+=2*k)
        for(int j = 0;j<k/2;++j){
            swap(s[j+index],s[index+k-1-j]);
            cout << j+index << "  " << index+k-1-j << endl;
        }
    if(index < s.length())
        for(int j = 0;j<(s.length()-index)/2;++j)
            swap(s[j+index],s[s.length()-1-j]);
    return s;
}

int main(){
    string s = "abcdefg";
    cout << s.length() << endl;
    cout << reverseStr(s, 2) << endl;
}