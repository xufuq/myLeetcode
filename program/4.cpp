//
// Created by Dell on 2021/3/23.
//

#ifndef PROGRAM_NO4_H
#define PROGRAM_NO4_H
#include <vector>
using namespace std;
double No4(vector<int>& nums1, vector<int>& nums2) {
    auto s1End = nums1.end(),s1Begin = nums1.begin();
    auto s2End = nums2.end(),s2Begin = nums2.begin();
    int totalSize = nums1.size() + nums2.size();
    int ds = totalSize%2, middleNum = totalSize/2;
    cout << ds << " " << middleNum << endl;
    double average=0;
    vector<int> nums3;
    for(int i=0;i<middleNum+1;i++)
    {
        int s1 = s1Begin == s1End ? 0x3f3f3f3f : *s1Begin;
        int s2 = s2Begin == s2End ? 0x3f3f3f3f : *s2Begin;
        if (s1<s2){
            nums3.push_back(s1);
            ++s1Begin;
        }
        else{
            nums3.push_back(s2);
            ++s2Begin;
        }
    }
    if (ds == 1)
        average = nums3[middleNum];
    else
        average = (nums3[middleNum-1] + nums3[middleNum]) / 2.0;
    return average;
}

#endif //PROGRAM_NO4_H
