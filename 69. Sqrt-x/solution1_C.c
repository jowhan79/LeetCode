// 2017/11/06 Jowhan

/****************************************************
Runtime: 12 ms
分析: 使用recursive拖慢程式執行速度
****************************************************/

int _mySqrt_recursive(long long int x, long long int begin, long long int end){
           
    if( begin==end ) return end; 
    if( end-begin==1 ){
        if( x>=end*end ) return end;
        else return begin;
    }
    
    long long int pivot = (end+begin)/2;
    
    if( x<pivot*pivot ) return _mySqrt_recursive(x,begin,pivot);
    if( pivot*pivot<x ) return _mySqrt_recursive(x,pivot,end);
    
    return pivot;
}

int mySqrt(int x) {    
    return _mySqrt_recursive(x,0,x);    
}
