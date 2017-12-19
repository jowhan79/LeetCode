// 2017/12/19 Jowhan

void swap(char *a, char *b){
    if( *a==*b ) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;    
}

void reverseArray(char *array, int arraySize){
    int i, j;
    for( i=0,j=arraySize-1 ; i<j ; ++i,--j ){
        swap(&array[i],&array[j]);
    }
}

char* reverseWords(char* s) {
    int substr_begin=0, substr_end=0;
    while( s[substr_end]!=0 ){
        
        // locate substr end
        substr_end = substr_begin;
        while( s[substr_end]!=0 && s[substr_end]!=' ' ) ++substr_end;
        
        // reverse
        reverseArray(&s[substr_begin], substr_end-substr_begin);
            
        // locate next substr begin
        substr_begin = substr_end+1;
    }
    
    return s;
}
