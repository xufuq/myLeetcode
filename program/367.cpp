

bool isPerfectSquare(int num) {
    if (num<=1)
        return true;
    int min=0, max=num, mid = num/2;
    while(min<max){
        if(num/mid > mid)
            min=mid+1;
        else if(num/mid < mid)
            max = mid-1;
        else if(mid*mid==num)
            return true;
        else 
            return false;
        mid = (min+max)/2;
    }
    if (mid*mid==num)
        return true;
    else
        return false;
    
}