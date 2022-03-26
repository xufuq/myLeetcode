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
#include <queue>
using namespace std;

int hIndex(vector<int>& citations) {
    if(citations.empty() || citations.back()==0) return 0;
    int n=citations.size();
    int start = 0, end = n-1, mid=(start+end)/2, result =0;
    while(start < end) {
        if(citations[mid]==n-mid)
            return citations[mid];
        else if(citations[mid]>n-mid) {
            result=max(result, n-mid);
            end = mid;
        }
        else {
            result=max(result, citations[mid]);
            start=mid+1;
        }
        mid=(start+end)/2;
    }
    if(result==0 && citations.back()>0)
        return 1;
    return result;
}