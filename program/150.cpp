#include <stack>
#include <string>
#include <vector>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> nums;
    for(auto c : tokens) {
        int x1 = nums.top();
        nums.pop();
        int x2 = nums.top();
        nums.pop();
        int x3;
        if(c == "*"){
            x3 = x1*x2;
            nums.push(x3);
        }
        else if(c == "/"){
            x3 = x1/x2;
            nums.push(x3);
        }
        else if(c == "+"){
            x3 = x1+x2;
            nums.push(x3);
        }
        else if(c == "-"){
            x3 = x1-x2;
            nums.push(x3);
        }
        else{
            x3 = atoi(c.c_str());
            nums.push(x1);
            nums.push(x2);
            nums.push(x3);
        }
    }
    return nums.top();
}

int main(){
    
}