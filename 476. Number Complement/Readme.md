# 476. Number Complement

## 題目敘述:

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.

Example 1:
```
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
```

Example 2:
```
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
```

## 解題想法:

1. 使用~num可以直接反轉整數的所有bits，但是題目要求不可算入前導0位元，因此不可直接使用NOT。
2. 如果能將給予整數的前導0位元全變成1那就可以直接使用NOT求得答案。
3. 避免使用逐位元變更，因此舉例並設法找出**直接由整數轉為對應負數**的規律。
```
輸入:     [ 6] 00000110
前導0變1: [-2] 11111110
輸出:     [ 1] 00000001

輸入:     [ 4] 00000100
前導0變1: [-4] 11111100
輸出:     [ 3] 00000011

輸入:     [ 3] 00000011
前導0變1: [-1] 11111111
輸出:     [ 0] 00000000

輸入:     [ 2] 00000010
前導0變1: [-2] 11111110
輸出:     [ 1] 00000001

輸入:     [ 1] 00000001
前導0變1: [-1] 11111111
輸出:     [ 0] 00000000
```
4. 由上可發現，規律為[輸入]-[前導0變1]=2^i，其中i為變化位元的最後一位。移項可得[前導0變1]=[輸入]-2^i。
5. 找出i的方法使用迴圈逐一確認[輸入]是否小於2^i，成立即可得i。
6. 最後對此負數取NOT即為答案。

## 程式碼 (C語言)
```c
int findComplement(int num){
    int i, neg;

    if(num==0) return 1;
    
    // find 2's base
    for( i=0; num>=(1<<i) && i<31 ; ++i );
    
    // transfer to negative
    neg = num - (1<<i);
    
    return ~neg;    
}
```


