#include <vector>
#include <algorithm>
using namespace std;

int getMaximumGenerated(int n) {
    if(n==0) return 0;
    vector<int> vec(n+1, 0);
    vec[1]=1;
    int result=1;
    for(int i=2;i<=n;++i){
        if(i%2) vec[i]=vec[i/2]+vec[i/2+1];
        else vec[i]=vec[i/2];
        result = max(result, vec[i]);
    }
    return result;
}