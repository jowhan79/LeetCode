int findComplement(int num){
    int i, neg;

    if(num==0) return 1;
    
    // find 2's base
    for( i=0; num>=(1<<i) && i<31 ; ++i );
    
    // transfer to negative
    neg = num - (1<<i);
    
    return ~neg;    
}
