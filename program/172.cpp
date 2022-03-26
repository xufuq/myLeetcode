#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
using namespace std;

int trailingZeroes(int n) {
    int result = 0, mul=1;
    for(int i=1;i<=n;i++) {
        mul*=i;
        while(mul%10==0) {
            ++result;
            mul/=10;
        }
    }
    return result;
}

int trailingZeroes(int n) {
    int result = 0, mul=1;
    for(int i=1;i<=n;i++) {
        while(i!=0 && i%5==0) {
            ++result;
            i/=5;
        }
    }
    return result;
}

int trailingZeroes(int n) {
    int result = 0;
    while(n>0){
        result+=n/5;
        n/=5;
    }
    return result;
}