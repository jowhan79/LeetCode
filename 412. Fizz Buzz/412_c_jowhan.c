// 2017/12/19 Jowhan

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    int i;
    char **result;
    
    // initialize
    result = malloc(n*sizeof(char*));
    for( i=0; i<n; ++i ){
        result[i] = malloc(10);
    }
    
    // create strings by given rules
    for( i=1; i<=n; ++i ){
        if( i%15==0 ) strcpy(result[i-1],"FizzBuzz");
        else if( i%3==0 ) strcpy(result[i-1],"Fizz");
        else if( i%5==0 ) strcpy(result[i-1],"Buzz");
        else sprintf(result[i-1],"%d",i);
    }
    
    *returnSize = n;
    return result;
}
