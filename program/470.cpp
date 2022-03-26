
// 两次rand7产生的数相乘，然后找概率相等的10个数，对应为1-10即可
int rand10() {
    int row, col, idx;
    do {
        row=rand7();
        col=rand7();
        idx=col+(row-1)%7;
    }while(idx>40)
    return 1+(idx-1)%10;
}