
// 位操作
int getSum(int a, int b) {
    bool aT, bT, nextT=false;
    unsigned int count=0x80000000, base=1;
    int res = 0;
    while(count>0) {
        aT=a&1;
        bT=b&1;
        if(aT^bT^nextT) { //1个或3个1
            res|=base; //
            if(aT&bT&nextT) //3个1
                nextT=true;
            else
                nextT=false;
        } else { //0个或2个1
            if(aT|bT|nextT)
                nextT=true;
            else
                nextT=false;
        }
        count=count>>1;
        base=base<<1;
        a=a>>1;
        b=b>>1;
    }
    return res;
}