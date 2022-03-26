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

int countPrimes(int n) {
    int result = 0;
    vector<int> primes(n);
    for(int i = 2; i < n;++i){
        if(primes[i]==0){ // 为0则是质数
            for(int j=1;j*i<n;++j)
                primes[i*j] = 1;
            ++result;
        }
    }
    return result;
}