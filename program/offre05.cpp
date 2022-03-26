#include <string>
#include <iostream>

using namespace std;

int main(int arg){
    string s = "fsf sdfs s f";
    s.replace(3,1,"%");
    cout << s << endl;
}