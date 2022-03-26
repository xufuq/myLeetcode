#include <vector>
#include "iostream"
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int count = 1, current=nums[0];
    for(int i=0; i<nums.size();++i) {
        if(current!=nums[i]){
            current=nums[i];
            nums[count] = current;
            ++count;
        }
    }
    for (int i = 0; i < count; ++i)
        cout << nums[i] << " " ;
    return count;
}