// 2017/12/19 Jowhan

void swap(char *a, char *b){
    if( *a==*b ) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;    
}

char* reverseString(char* s) {
    int i, j, stringSize=0;
    // calculate string size
    for( i=0; s[i]!=0; ++i ) ++stringSize;
    // reverse
    for( i=0,j=stringSize-1 ; i<j ; ++i,--j ){
        swap(&s[i],&s[j]);
    }
    return s;
}
