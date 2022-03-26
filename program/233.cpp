using namespace std;

int countDigitOne(int n) {
    int left=1, current=1, right=1, base=1;
    int result=0;
    while (n/base!=0){
        left = n/10/base;
        current = (n/base)%10;
        right = n%base;
        if(current==0)
            result += left*base;
        else if(current==1)
            result += left*base+right+1;
        else
            result += (left+1)*base;
        if(left==0)
            return result;
        base*=10;
    }
    return result;
}