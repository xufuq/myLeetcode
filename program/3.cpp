//
// Created by Dell on 2021/3/23.
//
#ifndef PROGRAM_NO3_H
#define PROGRAM_NO3_H
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

// 不行，很难按照这种集合找到合适的
//int lengthOfLongestSubstring(string s) {
//    cout << s.size() << " " << s << endl;
//    string nowBestStr;
//    int sLen = s.size();
//    map<char, vector<int>> strMap;
//    // 找到所有多次出现的字符
//    for(int i=0;i<sLen;i++){
//        if (strMap.find(s[i]) == strMap.end()) // 查找当前元素是否存在
//            strMap.insert({s[i], vector<int>{i}});
//        else // 说明之前已经插入过这个元素
//            strMap[s[i]].push_back(i);
//    }
//    return 0;
//}

int lengthOfLongestSubstring(string s) {
    int rightCur=-1,maxLen=0, reNum;
    int sLen = s.size();
//    unordered_set<char> strSet;
//    for(int leftCur=0;leftCur<sLen-maxLen;leftCur++){
//        if(leftCur != 0)
//            strSet.erase(s[leftCur-1]); // 从左侧开始删，以删掉跟右边重复的那个
//        while (rightCur+1<sLen && !strSet.count(s[rightCur+1])){
//            strSet.insert(s[++rightCur]);
//        }
//        maxLen = max(maxLen,rightCur-leftCur+1);
//    }
    map<char, int> strMap;
    for(int leftCur=0;leftCur<s.size()-maxLen;){
        auto it = strMap.end();
        while (rightCur+1<s.size()){
            it = strMap.find(s[rightCur+1]);
            if (it==strMap.end()){
                ++rightCur;
                strMap.insert({s[rightCur],rightCur});
            }
            else{
                reNum = it->second;
                for(int i=leftCur;i<=reNum;++i)
                    strMap.erase(s[i]);
                break;
            }
        }
        maxLen = max(maxLen,rightCur-leftCur+1);
        leftCur = reNum+1;
    }
    return maxLen;
}

#endif //PROGRAM_NO3_H
