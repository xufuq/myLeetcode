#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> countBits(int n) {
    vector<int> result(n+1, 0);
    unsigned int base=1;
    for(unsigned int i=1; i<=n; i++){
        if(i==base*2)
            base*=2;
        result[i]=1+result[i-base];
    }
    return result;
}