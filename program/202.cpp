#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "math.h"

using namespace std;

bool isHappy(int n) {
    unordered_set<int> set1;
    while (n!=1){
        if(set1.find(n)!=set1.end())
            return false;
        set1.insert(n);
        int num = pow(n%10, 2);
        n /= 10;
        while(n!=0){
            num += pow(n%10, 2);
            n /= 10;
        }
        n=num;
    }
    return true;
}

int main(){
    isHappy(2);
}