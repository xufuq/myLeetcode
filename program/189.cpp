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

void rotate(vector<int>& nums, int k) {
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin()+k, nums.end());
    reverse(nums.begin(), nums.end()); //
}