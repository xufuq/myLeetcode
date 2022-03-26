int hammingDistance(int x, int y) {
    x=x^y, y=0;
    for(int i=0; i<32;++i) 
        if(x>>i & 1) ++y;
    return y;
}