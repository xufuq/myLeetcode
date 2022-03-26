#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <iostream>
using namespace std;

// 这个失败了，有重复
vector<vector<int>> threeSum1(vector<int>& nums) {
    vector<vector<int>> result;
    unordered_map<int, vector<vector<int>>> pre;
    for(int i = 0; i < nums.size();++i) {
        for(int j = i+1; j < nums.size();++j){
            pre[nums[i]+nums[j]].push_back({nums[i], nums[j]});
            for(int k = j+1; k < nums.size();++k){
                auto it = pre.find(-nums[k]);
                if(it != pre.end()){
                    auto vec = it->second;
                    for(auto v : vec){
                        v.push_back(k);
                        result.push_back(v);
                    }
                    
                }
            }
        }
    }
    return result;
}

// 失败，超时了
vector<vector<int>> threeSum2(vector<int>& nums) {
    set<multiset<int>> result; // set避免重复, multiset用来实现排序
    unordered_map<int, set<multiset<int>>> pre;
    for(int i = 0; i < nums.size();++i) {
        for(int j = i+1; j < nums.size();++j){
            pre[nums[i]+nums[j]].insert({nums[i], nums[j]});
            for(int k = j+1; k < nums.size();++k){
                auto it = pre.find(-nums[k]);
                if(it != pre.end()){
                    auto myset = it->second;
                    for(auto st : myset){
                        st.insert(nums[k]);
                        result.insert(st);
                    }
                }
            }
        }
    }
    vector<vector<int>> r;
    for(auto st : result)
        r.push_back(vector<int>(st.begin(), st.end()));
    
    return r;
}

// 成功
vector<vector<int>> threeSum3(vector<int>& nums) {
    multiset<int> minuxNum, zeroNum, plusNum;
    set<multiset<int>> result;
    for(auto n : nums){
        if(n<0 && minuxNum.count(n)<2)
            minuxNum.insert(n);
        else if(n==0)
            zeroNum.insert(0);
        else if(n>0 && plusNum.count(n)<2)
            plusNum.insert(n);
    }
    
    // 全为0
    if(zeroNum.size()>2)
        result.insert({0, 0, 0});
    if(zeroNum.size() > 0) // 有0的情况下
        for(auto m : minuxNum)
            if(plusNum.find(-m)!=plusNum.end())
                result.insert({m,0,-m});

    for(auto m1 = minuxNum.begin(); m1 != minuxNum.end();++m1){
        ++m1;
        for(auto m2 = --m1; m2!=minuxNum.end();++m2)
            if(plusNum.find(-*m1-*m2)!=plusNum.end())
                result.insert({*m1, *m2, -*m1-*m2});
    }
        

    for(auto m1 = plusNum.begin(); m1 != plusNum.end();++m1){
        ++m1;
        for(auto m2 = --m1; m2!=plusNum.end();++m2)
            if(minuxNum.find(-*m1-*m2)!=minuxNum.end())
                result.insert({*m1, *m2, -*m1-*m2});
    }
        

    vector<vector<int>> r;
    for(auto st : result)
        r.push_back(vector<int>(st.begin(), st.end()));
    
    return r;
    
}


// map保存前两个循环
vector<vector<int>> threeSum4(vector<int>& nums) {
    unordered_map<int, vector<set<int>>> preMap;
    set<multiset<int>> result;
    for(int i=0; i < nums.size();++i)
        for(int j= i;j< nums.size();++j)
            preMap[nums[i]+nums[j]].push_back(set<int>{i, j});

    for(int i=0; i < nums.size();++i){
        auto it = preMap.find(-nums[i]);
        if(it != preMap.end()){
            vector<set<int>> indexSet = it->second;
            for(auto &iS : indexSet){
                iS.insert(i);
                if(iS.size()==3){ // 没有重复坐标
                    auto iBegin = iS.begin();
                    result.insert({nums[*iBegin++], nums[*iBegin++], nums[*iBegin++]});
                }
            }
        }
    }
    vector<vector<int>> r;
    for(auto st : result)
        r.push_back(vector<int>(st.begin(), st.end()));
    
    return r;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto result = threeSum4(nums);
    for(auto vv : result){
        for(auto v : vv)
            cout << v << " ";
        cout << std::endl;
    }
}