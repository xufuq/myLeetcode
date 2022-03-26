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

string solveEquation(string equation) {
    istringstream is(equation);
    string left, right;
    getline(is, left, '=');
    getline(is, right);
    int xCount=0, sum=0, sIndex=0;
    for(int i=0; i<left.length(); i++) {
        if(left[i]=='x') {
            cout << left.substr(sIndex, i-sIndex+1) << endl;
            if(sIndex==i) 
                ++xCount;
            else if(sIndex==i-1) {
                if(sIndex==0 && isdigit(left[sIndex])) 
                    xCount+=left[0]-'0';
                else if(left[sIndex]=='+')
                    ++xCount;
                else 
                    --xCount;
            }
            else { // i-sIndex>=2
                int c=stoi(left.substr(sIndex, i-sIndex));
                xCount+=c;
            }
            cout << "count: " << xCount << endl;
            sIndex=i+1;
        } else if(left[i]=='+' || left[i]=='-' || i==left.length()-1) {
            if(sIndex==i) continue;
            cout << left.substr(sIndex, i-sIndex+1) << endl;
            int c;
            if(i==left.length()-1) c=stoi(left.substr(sIndex, i-sIndex+1));
            else c=stoi(left.substr(sIndex, i-sIndex));
            sum-=c;
            sIndex=i;
        }   
    }
    sIndex=0;
    for(int i=0; i<right.length(); i++) {
        if(right[i]=='x') {
            cout << right.substr(sIndex, i-sIndex+1) << endl;
            if(sIndex==i) 
                --xCount;
            else if(sIndex==i-1) {
                if(sIndex==0 && isdigit(right[sIndex])) 
                    xCount-=right[0]-'0';
                else if(right[sIndex]=='+')
                    --xCount;
                else 
                    ++xCount;
            }
            else { // i-sIndex>=2
                int c=stoi(right.substr(sIndex, i-sIndex));
                xCount-=c;
            }
            cout << "count: " << xCount << endl;
            sIndex=i+1;
        } else if(right[i]=='+' || right[i]=='-' || i==right.length()-1) {
            if(sIndex==i) continue;
            cout << right.substr(sIndex, i-sIndex+1) << endl;
            int c;
            if(i==right.length()-1) c=stoi(right.substr(sIndex, i-sIndex+1));
            else c=stoi(right.substr(sIndex, i-sIndex));
            sum+=c;
            sIndex=i;
        }   
    }
    if(xCount==0 && sum!=0) return "No solution";
    else if(xCount==0 && sum==0) return "Infinite solutions";
    return string("x=")+to_string(sum/xCount);
}

int main() {
    string equation="2x+3x-6x=x+2";
    solveEquation(equation);
}