// 2017/11/29 Peony

#define MIN(a,b) a>b ? b: a

int _coinChange_dp(int* coins, int coinsSize, int amount){
    
    int table[amount+1], i, j, head, curmin;
    memset(table, 0, sizeof(table));
    
    for(i=1; i<=amount; i++){
        for(j=0, curmin=amount+1; j<coinsSize; j++){
            if((i-coins[j])>=0){
                curmin = MIN(table[i-coins[j]]+1, curmin);
            }
        }
        table[i]=curmin;
    }
    
    return table[amount] < (amount +1)? table[amount]: -1;
}


int coinChange(int* coins, int coinsSize, int amount) {
    return _coinChange_dp(coins, coinsSize, amount);    
}
