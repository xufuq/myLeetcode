#include <list>
#include <iostream>
using namespace std;

list<list<int>> get_list(list<int> L){
    int count = 0, Len=1;
    list<list<int>> result;
    if(L.empty()) return result;
    result.push_back(list<int>());
    for(auto it=L.begin(); it!=L.end();++it){
        ++count;
        result.back().push_back(*it);
        cout << "L: " << *it << " ";
        if(count==Len){
            ++Len;
            count = 0;
            result.push_back(list<int>());
        }
    }
    return result;
}

int main(){
    list<int> L={1, 2, 5, 68, 90, 3};
    auto result=get_list(L);
    for(auto it=result.begin(); it!=result.end();++it){
        for(auto it2=it->begin(); it2!=it->end();++it2){
            cout << *it2 << " ";
        }
        cout << endl;
    }
}