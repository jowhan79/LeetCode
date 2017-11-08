// 2017/11/08 Jowhan
// Total 2 solutions.

class Solution {
public:
    vector<int> countBits(int num) {
        return _countBits_solution2(num);
    }

private:
    inline vector<int> _countBits_solution1(int num){
        // fastest method for single input
        const int m1 = 0x55555555;
        const int m2 = 0x33333333;
        const int m4 = 0x0f0f0f0f;
        const int m8 = 0x00ff00ff;
        const int m16 = 0x0000ffff;
        vector<int> hamming_weight;
        
        for(int i=0; i<=num; ++i){
            hamming_weight.push_back(i);
            hamming_weight[i] = (hamming_weight[i] & m1) + (hamming_weight[i]>>1 & m1);
            hamming_weight[i] = (hamming_weight[i] & m2) + (hamming_weight[i]>>2 & m2);
            hamming_weight[i] = (hamming_weight[i] & m4) + (hamming_weight[i]>>4 & m4);
            hamming_weight[i] = (hamming_weight[i] & m8) + (hamming_weight[i]>>8 & m8);
            hamming_weight[i] = (hamming_weight[i] & m16) + (hamming_weight[i]>>16 & m16);
        }
        
        return hamming_weight;
    }
    
    inline vector<int> _countBits_solution2(int num){
        // DP solution: more suitable for this problem
        vector<int> hamming_weight;
        
        hamming_weight.push_back(0);
        for( int i=1; i<=num; ++i ){
            hamming_weight.push_back( (i & 1) + hamming_weight[i>>1] );
        }
        
        return hamming_weight;
    }
};
