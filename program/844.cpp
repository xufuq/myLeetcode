#include <string>
#include <vector>
#include <stack>

using namespace std;

// 要求空间复杂度为1，不能用堆栈
bool backspaceCompare(string s, string t) {
    int s_ = 0, t_ =0; // 回退符的个数
    int s_index=s.length()-1, t_index=t.size()-1;
    while(s_index>=0 || t_index>=0){
        while(s_index>=0 && (s_>0 || s[s_index]=='#')){  // 因为index大于0，所以可以判断s_
            if(s[s_index]=='#')
                ++s_;
            else
                --s_;
            --s_index;
        }
        while(t_index>=0 && (t_>0 || t[t_index]=='#')){
            if(t[t_index]=='#')
                ++t_;
            else
                --t_;
            --t_index;
        }
        if(s_index>=0 && t_index>=0){ // 都大于等于0
            if(s[s_index]!=t[t_index])
                return false;
            --t_index;
            --s_index;
        }
        else if((s_index<0 && t_index<0))
            return true;
        else
            return false;
    }
    return true;
}