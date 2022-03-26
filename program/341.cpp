#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <stack>
using namespace std;

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        it=nestedList.begin();
        end=nestedList.end();
    }
    
    int next() {
        if(it->isInteger()) {
            int n=it->getInteger();
            ++it;
            return n;
        } else { // 又是一个 嵌套结构
            int n=deepIterator->next();
            if(!deepIterator->hasNext()) ++it;
            return n;
        }
    }
    
    bool hasNext() {
        if(it==end) return false;
        if(it->isInteger()) return true;
        else {  // 当前位置是一个列表
            if(deepIterator!=nullptr && deepIterator->hasNext()) return true;
            else { // 如果到顶，在next函数中已经自加过
                deepIterator=new NestedIterator(it->getList());
                if(deepIterator->hasNext()) return true;
                else {
                    ++it;
                    return hasNext();
                } 
            }
        }
    }
    vector<NestedInteger>::iterator it, end;
    NestedIterator *deepIterator=nullptr;
};