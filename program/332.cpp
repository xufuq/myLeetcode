#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;
vector<string> result;

bool findItinerary(vector<vector<string>>& tickets, string start, vector<bool> &isUsed) {
    if(result.size()==tickets.size()+1) return 1;

    // 这里的遍历浪费了时间，可以把映射关系存储到map的当中
    for(int i=0; i<tickets.size(); ++i) { // 这里有可能比较出来的最小路径会不通，所以需要考虑多种结果
        if(tickets[i][0]!=start || isUsed[i]) continue;
        result.push_back(tickets[i][1]);
        isUsed[i] = true;
        if(findItinerary(tickets, tickets[i][1], isUsed))
            return 1;
        isUsed[i] = false;
        result.pop_back();
    }

    return 0;
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    sort(tickets.begin(), tickets.end());
    vector<bool> isUsed(tickets.size(), false);
    result.push_back("JFK");
    findItinerary(tickets, "JFK", isUsed);
    return result;
}

int main()
{
    vector<vector<string>> str1={{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    findItinerary(str1);
    for(auto v : result)
        cout<<v<<" ";
    cout<<endl;
}