#include <stack>

using namespace std;
bool isValid(string s) {
    stack<char> brackets;
    for(auto ss : s){
        if(ss=='(' || ss== '[' || ss == '{')
            brackets.push(ss);
        else{
            if((!brackets.empty())&&(brackets.top()==ss-1 || brackets.top()==ss-2))
                brackets.pop();
            else
                return false;
        }
    }
    if(brackets.empty())
        return true;
    else
        return false;
}