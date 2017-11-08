// 2017/11/08 Peony

int climbStairs(int n) {
    
    int i;
    int counting[n>2?n:2];
    counting[0] = 1;
    counting[1] = 2;
    for(i=2; i<n; i++){
        counting[i] = counting[i-1] + counting[i-2];
    }
    return counting[n-1];
}
