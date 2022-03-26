#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int gIndex=0, sIndex=0;
    while(sIndex<s.size() && gIndex<g.size()){
        if(s[sIndex]>=g[gIndex])
            ++gIndex;
        ++sIndex;
    }
    return gIndex;
}