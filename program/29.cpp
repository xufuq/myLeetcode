#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include "math.h"
using namespace std;

// 直接用二进制计算
// 二进制计算应该是从高位向地位，所以这里才有问题
// int divide(int dividend, int divisor) {
//     int signs=1, extra = 0;
//     if(dividend==INT_MIN && divisor==INT_MIN) return 1;
//     if(divisor==INT_MIN) return 0;
//     else if(divisor<0) {
//         signs =-signs;
//         divisor = -divisor;
//     }
//     if(dividend==INT_MIN) {
//         signs =-signs;
//         dividend++;
//         extra=1;
//         dividend=-dividend;
//     } else if(dividend<0){
//         signs =-signs;
//         dividend = -dividend;
//     }
//     int dividendBack=0, dividsorBack=divisor;
//     while(divisor>0){
//         dividendBack=dividendBack<<1+ dividend&1;
//         divisor=divisor>>1;
//         dividend=dividend>>1;
//     }
//     dividend=dividend<<1; // 这样才是倍数
//     if(dividendBack>=dividsorBack) dividend+=1;
//     if(extra) { // dividend是INT_MIN
//         if(signs>0) { //是正的，有可能溢出
//             if(dividend==INT_MIN) return INT_MIN;
//             else dividend += 1;
//         }
//         else {
//             dividend = -dividend;
//             dividend-=1; //
//         }
//     }
//     else if(signs<0) dividend = -dividend;
//     return dividend;
// }



// 用递归做，得先转换数据类型
// 看答案解析里面的一种做法
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend>INT_MIN) return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
            return INT_MAX;// 是最小的那个，那就返回最大的整数啦
        }
        long a = dividend;
        long b = divisor;
        int sign = 1; 
        if((a>0&&b<0) || (a<0&&b>0)){
            sign = -1;
        }
        a = a>0?a:-a;
        b = b>0?b:-b;
        long res = div(a,b);
        if(sign>0)return res>INT_MAX?INT_MAX:res;
        return -res;
    }
    int div(long a, long b){  // 似乎精髓和难点就在于下面这几句
        if(a<b) return 0;
        long count = 1;
        long tb = b; // 在后面的代码中不更新b
        while((tb+tb)<=a){
            count = count + count; // 最小解翻倍
            tb = tb+tb; // 当前测试的值也翻倍
        }
        return count + div(a-tb,b);
    }
};


// 除法从高位开始
int divide(int dividend, int divisor) {
    int signs=1;
    long result = 0;
    if(dividend==INT_MIN && divisor==INT_MIN) return 1;
    if(dividend==INT_MIN){
        if(divisor==-1)
            return INT_MAX;
        else if(divisor==1)
            return dividend;
    }
    if(divisor==INT_MIN) return 0;
    long a, b;
    if((divisor<0&&dividend>0) ||(divisor>0&&dividend<0)) signs=-1;
    a=abs((long)dividend), b=abs((long)divisor);
    int bitMoved=0;
    while((b<<(bitMoved+1)) <= a)
        ++bitMoved;
    cout << bitMoved << endl;
    while(bitMoved>=0) {
        if(a>>bitMoved >= b) {
            a-=b<<bitMoved;
            result=result+(1<<bitMoved);
        }
        --bitMoved;
    }
    if(signs<0) result=-result;
    return (int)result;
}

int main() {
    cout << divide(7, -3);
    return 0;
}