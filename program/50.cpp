#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<int, double> mp; 

double myPow(double x, int n) {
    if(x==0) return 0;
    if(n==1) return x;
    else if(n==0) return 1;
    if(mp[n]!=0) return mp[n];
    double result=1;
    unsigned int count=abs(n), a=1;
    while(2*a<count) a*=2;
    result *= myPow(x, a);
    result *= myPow(x, count-a);
    if(n<0) result=1/result;
    mp[n]=result;
    return result;
}

double myPow(double x, int n) {
    if(x==0) return 0;
    if(n==1) return x;
    else if(n==0) return 1;
    if(mp[n]!=0) return mp[n];
    unsigned int count=abs(n), a=2;
    mp[0]=1, mp[1]=x;
    while(a<count) {
        mp[a]=mp[a/2]*mp[a/2];
        a*=2;
    }
    double result=1;
    while(count>0){
        if(count>=a){
            result *= mp[a];
            count-=a;
        }
        a/=2;
    }
    if(n<0) result=1/result;
    return result;
}

// 官方题解，思路很好，把奇数变成偶数，便于求解
class Solution {
public:
    double quickMul(double x, long long N) {
        double ans = 1.0;
        // 贡献的初始值为 x
        double x_contribute = x;
        // 在对 N 进行二进制拆分的同时计算答案
        while (N > 0) {
            if (N % 2 == 1) {
                // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_contribute;
            }
            // 将贡献不断地平方
            x_contribute *= x_contribute;
            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            N /= 2;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

int main(){
    double x=0.00001;
    int n=2147483647;
    cout << myPow(x, n) << endl;
}