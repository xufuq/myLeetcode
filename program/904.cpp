#include <vector>
#include "iostream"
using namespace std;

int totalFruit(vector<int>& fruits) {
        if (fruits.empty()) return 0;
        
        int a_start=0, last_start=0;
        int a=fruits[0], b=a, ab_last=a;
        int maxCount=0, i = 0;
        for (i = 0; i < fruits.size(); i++)
        {
            if(fruits[i]!=a && fruits[i]!=b){
                maxCount=maxCount>i-a_start?maxCount:i-a_start;
                a=ab_last;
                a_start=last_start;
                b=fruits[i];
            }
            if(fruits[i]!=ab_last){
                ab_last = fruits[i];
                last_start = i;
            }
        }
        maxCount=maxCount>i-a_start?maxCount:i-a_start;
        return maxCount;
    }

int main(){
    vector<int> nums = {1,0,3,4,3};
    totalFruit(nums);
}