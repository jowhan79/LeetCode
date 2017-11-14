// 2017/11/14 Peony
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        return findDuplicates_v1(nums);
    }

private:
    vector<int> findDuplicates_v1(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<int> ans;
        ans.clear();
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1])
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
