#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
using namespace std;

int titleToNumber(string columnTitle) {
    int result = 0;
    for(int i = 0; i < columnTitle.size(); i++) {
        result*=26;
        result += columnTitle[i]-'A'+1;
    }
    return result;
}