// 2017/11/07 Jowhan

int climbStairs(int n) {
    // can solved by DP
    if(n<=1) return 1;
    
    int ways[n], i;
    
    ways[0] = 1;
    ways[1] = 2;

    for( i=2; i<n; ++i ){
        ways[i] = ways[i-1] + ways[i-2];
    }
    
    return ways[n-1];
}
