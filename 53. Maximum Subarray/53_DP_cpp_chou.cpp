// 2017/11/04 Peony
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxVal=0, lastVal;
        vector<int>::iterator item;
        for(item=nums.begin()+1, lastVal=*nums.begin(), maxVal = lastVal; item!=nums.end(); item++){
            lastVal = lastVal<0 ? ( lastVal>*item?lastVal:*item ):( lastVal+*item );
            maxVal = maxVal > lastVal ? maxVal: lastVal;
        }
        
        return maxVal;
    }
};
