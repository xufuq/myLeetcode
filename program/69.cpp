#include <iostream>


// x/middle防止溢出
int mySqrt(int x) {
    int start=1, end=2, middle=(start+end)/2;
    while (end < x){
        start = end;
        end = 2*end;
    }
    middle=(start+end)/2;
    while(end - start > 1){
        if(x == middle*middle)
            return middle;
        else if(middle*middle < x)
            start = middle;
        else
            end = middle;
        middle = (start+end)/2;
    }
    if(end*end <= x)
        return end;
    else
        return start;
}