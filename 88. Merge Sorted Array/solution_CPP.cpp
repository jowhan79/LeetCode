// 2017/11/08 Jowhan

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1=m-1, index2=n-1, index_new=m+n-1;
        
        for( ; index1>=0 && index2>=0; --index_new ){
            if( nums1[index1]>nums2[index2] ){
                nums1[index_new] = nums1[index1--];
            }
            else{
                nums1[index_new] = nums2[index2--];
            }
        }
        
        for( ; index2>=0; --index2 ){
            nums1[index2] = nums2[index2];
        }
    }
};
