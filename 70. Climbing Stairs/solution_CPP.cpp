// 2017/11/07 Jowhan

class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return n;
        
        vector<int> ways;
        ways.push_back(1);  // 1 step to top
        ways.push_back(2);  // 2 steps to top
        for( int i=2; i<n; ++i ){
            ways.push_back( ways[i-1]+ways[i-2] );
        }
        
        return ways[n-1];
    }
};
