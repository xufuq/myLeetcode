#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int save[3]={0};
    for(auto b : bills) {
        if(b==5)
            ++save[0];
        else if(b==10){
            if(save[0]==0) 
                return false;
            ++save[1];
            --save[0];
        }
        else if(b==20){
            if(save[1]>0 && save[0]>0){
                --save[1];
                --save[0];
                ++save[2];
            }
            else if(save[0]>2){
                save[0] -= 3;
                ++save[2];
            }
            else
                return false;
        }
    }
    return true;
}