// 2017/11/29 Jowhan

/********************** solution 1 **********************/
// DP

#define MIN(a,b) a < b ? a : b

inline int _coinChange_sol1(int* coins, int coinsSize, int amount) {   
    int DP_coinCount[amount+1];
    int i, j, min;
    
    memset(&DP_coinCount,0,sizeof(DP_coinCount));
    
    for( i=1; i<=amount; ++i ){
        for( j=0,min=amount+1; j<coinsSize; ++j ){
            if( i-coins[j]>=0 ){
                min = MIN(DP_coinCount[i-coins[j]]+1,min);
            }
        }
        DP_coinCount[i] = min;
    }
    
    /*for( i=0; i<amount+1; ++i ){
        printf("%d ",DP_coinCount[i]);
    }
    printf("\n");  */
    
    
    return DP_coinCount[amount]==amount+1 ? -1 : DP_coinCount[amount];
}
/********************************************************/

int coinChange(int* coins, int coinsSize, int amount) {
    return _coinChange_sol1(coins, coinsSize, amount);
}
