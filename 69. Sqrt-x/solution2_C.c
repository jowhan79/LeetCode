// 2017/11/06 Jowhan

/****************************************************
Runtime: 12 ms
分析: ...傻眼貓咪，改成loop還是相同的時間，一怒之下
複製3ms的code來submit，哎呀居然要19ms，那我不玩了XD
****************************************************/

int mySqrt(int x) {    
    // divide: every loop discard half possible values
    
    // use long long int to prevent overflow
    long long int begin=0, end=x, pivot, square;
    
    while(end-begin>1){
        // find middle
        pivot = (end+begin)/2;
        square = pivot*pivot;
        
        // check possible values are at left, right or just hit        
        if( square<x ) begin = pivot;
        else if( x<square ) end = pivot;
        else return pivot;
    }
    
    // remain at most 2 possible values
    if( x>=end*end )
        return end;    
    return begin;    
}
