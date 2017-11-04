// 2017/11/04 Jowhan

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> max_sum;
        int i;
        
        max_sum.push_back(nums[0]);
        
        for( i=1; i<nums.size(); ++i ){
            if( max_sum[i-1]<0 ){
                max_sum.push_back( max(max_sum[i-1],nums[i]) );
            }
            else{
                max_sum.push_back( max_sum[i-1]+nums[i] );
            }
        }
        
        return *max_element(max_sum.begin(), max_sum.end());
    }
};
