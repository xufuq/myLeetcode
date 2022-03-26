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

uint32_t reverseBits(uint32_t n) {
    for(int i=0;i<16;++i) {
        if(((n>>i) & 1)!=((n>>(31-i)) & 1)){
            if((n>>i) & 1) { //1
                n &=~(1<<i); //
                n |=1<<(31-i);
            } else { //
                n |=(1<<i); //
                n &=~(1<<(31-i)); //
            }
        }
    }
    return n; // return
}