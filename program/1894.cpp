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

int chalkReplacer(vector<int>& chalk, int k) {
    int sum = accumulate(chalk.begin(), chalk.end(), 0);
    k=k%sum;
    for(int i=0; i<chalk.size(); i++) {
        if(chalk[i]>k) return i;
        k-=chalk[i];
    }
    return 0;
}

int chalkReplacer(vector<int>& chalk, int k) {
    int mem=k;
    while(k>=0) {
        if(mem!=k)
            k%=(mem-k);
        for(int i=0; i<chalk.size(); i++) {
            if(chalk[i]>k) return i;
            k-=chalk[i];
        }
    } 
    return 0;
}