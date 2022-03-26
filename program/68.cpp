#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <stack>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    for(int i = 0; i < words.size();) {
        result.push_back(string());
        int wordCount=0;
        while(i < words.size() && result.back().length()+words[i].length()<=maxWidth) {
            result.back()+=words[i++]+" ";
            ++wordCount;
        }
        result.back().pop_back();
        if(i!=words.size()) {
            int extraBlank = maxWidth - result.back().length();
            if(wordCount==1) result.back()+=string(extraBlank, ' ');
            else {
                int ave=extraBlank/(wordCount-1), extraAve=extraBlank%(wordCount-1), blankCount=0;
                for(int i=result.back().length();i>=0;--i) {
                    if(result.back()[i]==' ') {
                        ++blankCount;
                        string blank;
                        if(blankCount<=wordCount-1-extraAve) blank=string(ave+1, ' ');
                        else blank=string(ave+2, ' ');
                        result.back().replace(result.back().begin()+i, result.back().begin()+i+1, blank);
                    }
                }
            }
        }
        else result.back()+=string(maxWidth - result.back().length(), ' ');    
    }
    return result;
}