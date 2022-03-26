#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include "math.h"
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

// 用一个哈希表保存员工序号和数组位置的关系
int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, int> mp;
    for(int i=0; i<employees.size(); i++) 
        mp[employees[i]->id]=i; 
    return getImportance(employees, id, mp);
}

int getImportance(vector<Employee*> employees, int id, unordered_map<int, int> &mp) {
    int result = employees[mp[id]]->importance;
    for(auto &pid : employees[mp[id]]->subordinates) // 获得下属的序号
        result += getImportance(employees, pid, mp);
    return result;
}
