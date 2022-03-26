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

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> result(n+1);
    for(auto book : bookings) {
        for(int i=book[0]; i<=book[1];++i)
            result[i]+= book[2];
    }
    result.erase(result.begin());
    return result;
}

// 差分法
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> result(n);
    for(auto book : bookings) {
        result[book[0]-1]+=book[2];
        result[book[1]]-= book[2];
    }
    for(int i=1;i<n;++i)
        result[i]+=result[i-1];
    return result;
}