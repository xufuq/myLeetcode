#include <set>
#include "vector"

using namespace std;


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> set1(nums1.begin(), nums1.end());
    vector<int> result;
    for(auto num2 : nums2) {
        if(set1.find(num2) != set1.end()){
            result.push_back(num2);
            set1.erase(num2);
        }   
    }
    return result;
}