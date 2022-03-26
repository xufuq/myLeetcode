#include <vector>
#include "iostream"

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result(2,-1);
    int startIndex = 0, nSize = nums.size() , endIndex = nSize-1, middleIndex = nSize/2;;
    if (nSize==0)
        return result;
    else{
        while (endIndex-startIndex>1)
        {
            if(nums[middleIndex]==target)
                break;
            else if(nums[middleIndex]<target){
                startIndex=middleIndex;
                middleIndex = (startIndex+endIndex)/2;
            }
            else{
                endIndex=middleIndex;
                middleIndex = (startIndex+endIndex)/2;
            }
        }
        if(nums[middleIndex]==target)
            result[0]=result[1]=middleIndex;
        else if(nums[startIndex]==target)
            result[0]=result[1]=startIndex;
        else if(nums[endIndex]==target)
            result[0]=result[1]=endIndex;
        else
            return result;

        while(result[0]-1>=0 && nums[result[0]-1]==target)
            --result[0];
        while(result[1]+1<nSize && nums[result[1]+1]==target)
            ++result[1];
        return result;
    }
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> result = searchRange(nums, 8);
    cout << result[0] << " " << result[1] ;
}