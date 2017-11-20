// 2017/11/20 Jowhan

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        return _fourSumCount_sol1(A, B, C, D);
    }
private:
    /********************** solution 1 **********************/
    // hash table: time: O(n^2), space: O(n^2)
    // C++有提供hash table，不用自己實作
    
    inline int _fourSumCount_sol1(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int i, j, count=0;
        unordered_map<int,int> AB_count_map;
        
        for( i=0; i<A.size(); ++i ){
            for( j=0; j<B.size(); ++j ){
                ++AB_count_map[A[i]+B[j]];
            }
        }
        
        for( i=0; i<C.size(); ++i ){
            for( j=0; j<D.size(); ++j ){
                count += AB_count_map[-(C[i]+D[j])];
            }
        }
        
        return count;
    }
    /********************************************************/
};
