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

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int len=flowerbed.size();
    if(len==1) {
        if(n==1 && flowerbed[0]==0) return true;
        else if(n==0) return true;
        else return false;
    }
    if(flowerbed[0]==0 && flowerbed[1]==0) {
        --n;
        flowerbed[0]=1;
    }
    for(int i=1;i<len-1;i++) {
        if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0) {
            flowerbed[i]=1;
            --n;
        }
    }
    if(flowerbed[len-1]==0 && flowerbed[len-2]==0)
        --n;
    if(n<=0) return true;;
    return false;
}