#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size();
    int sIndex = 0, eIndex = cols - 1, midIndex=(sIndex+eIndex)/2; 
    for(int row = 0; row < rows ;++row) {
        while(sIndex <= eIndex) {
            if(matrix[row][sIndex]==target) 
                return true;
            else if(matrix[row][midIndex]>target) {
                eIndex = midIndex;
                midIndex = (sIndex+eIndex)/2;
            }
            else {
                sIndex=midIndex+1;
                midIndex = (sIndex+eIndex)/2;
            }
        }
        if(matrix[row][midIndex]>target){
            eIndex=midIndex, sIndex=0, midIndex= (sIndex+eIndex)/2;
        }else {
            sIndex=0, eIndex= cols-1, midIndex= (sIndex+eIndex)/2;
        }
    }
    return false;
}
//官港题解，从左下角开始，当前值大于目标值则向上，当前值小于目标值则向右