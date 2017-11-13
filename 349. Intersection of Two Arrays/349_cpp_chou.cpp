//2017/11/13 Peony
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> ans, s1(nums1.begin(), nums1.end());
        ans.clear();
        
        for(int i: nums2){
            if(s1.find(i) != s1.end())
                ans.insert(i);
        }
        
        return vector<int>(ans.begin(), ans.end());
        
    }
};
