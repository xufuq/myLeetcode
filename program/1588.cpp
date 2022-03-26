#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>

using namespace std;

int sumOddLengthSubarrays(vector<int>& arr) {
    int sum=0;
    for(int i=1;i<arr.size();i+=2) {
        for(auto Lh=arr.begin(), Rh=Lh+i;Rh<arr.end();Lh++,Rh++) 
            sum=accumulate(Lh, Rh, sum);
    }
    return sum;
}

