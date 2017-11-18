// 2017/11/18 Jowhan

/********************** solution 1 **********************/
inline int _myAtoi_solution1(char* str){    
    if( str==NULL ) return 0;
    int i, j, is_negative=0, base, sum=0, valid_str_length, new_sum, temp;
    const int max_valid_str_size=11;
    char valid_str[11];
    
    memset(valid_str,0,max_valid_str_size);
    
    // extract valid int character: ' ', '-', '+', '0~9'
    
    // skip space
    for( i=0; str[i]!=0 && str[i]==' '; ++i );     
    
    // record negative or positive
    if( str[i]=='-' ){
        is_negative = 1; 
        ++i;
    }
    else if( str[i]=='+' ) ++i;
    
    // skip leading zeros
    for( ; str[i]!=0 && str[i]=='0'; ++i );
    
    // scan valid value
    for( j=0; str[i]!=0 && str[i]>='0' && str[i]<='9' && j<max_valid_str_size-1 ; ++i){
        valid_str[j++] = str[i];
    }
    
    // keep scan: if next digit still valid than overflow
    if( str[i]!=0 && str[i]>='0' && str[i]<='9' ){
        return is_negative ? INT_MIN : INT_MAX;
    }
    
    // check 10th digit to prevent overflow
    valid_str_length = strlen(valid_str);
    if( valid_str_length==10 && valid_str[0]>'2' ){
        return is_negative ? INT_MIN : INT_MAX;
    }
    
    // convert
    base = is_negative ? -1 : 1;    
    for( i=valid_str_length-1, sum=new_sum=0; i>=0 ; --i, base*=10 ){        
        temp = (valid_str[i]-'0')*base;
        new_sum = sum + temp;
        // check overflow
        if( new_sum>0 && is_negative ) return INT_MIN;
        if( new_sum<0 && !is_negative ) return INT_MAX;
        if( new_sum-sum!=temp ){
            return is_negative ? INT_MIN : INT_MAX;
        }
        
        sum = new_sum;
    }    
    
    return sum;
}
/********************************************************/


/********************** solution 2 **********************/
// (參考最快解答)
// 解一之缺點:
// 1. 額外耗費變數空間存valid_str
// 2. 過多冗餘判斷 (迴圈, overflow)
// 3. overflow在發生之前就判斷較佳

inline int _myAtoi_solution2(char* str){
    int i, is_negative=0, sum=0;    
    
    // skip spaces
    for( i=0; str[i]==' '; ++i );
        
    // record sign
    if( str[i]=='+' || str[i]=='-' ) is_negative = str[i++]=='-' ? 1 : 0;
    
    // skip leading zeros
    for( ; str[i]=='0'; ++i );
    
    // convert valid digits
    for( ; str[i]>='0' && str[i]<='9'; ++i ){
        
        if( sum>INT_MAX/10 || (sum==INT_MAX/10 && str[i]>'7') ){
            return is_negative ? INT_MIN : INT_MAX;
        }        
        sum = sum*10 + (str[i]-'0');
    }
    
    return is_negative ? -sum : sum;
}
/********************************************************/


int myAtoi(char* str) {
    return _myAtoi_solution2(str);
}
