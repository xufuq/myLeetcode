#include <string>

using namespace std;

bool checkRecord(string s) {
    int Acount=0, Lcount=0;
    for(auto c : s) {
        if(Acount>1 || Lcount>2)
            return false;
        if(c=='A')
            ++Acount;
        if(c=='L')
            ++Lcount;
        else 
            Lcount=0;
    }
    return true;
}