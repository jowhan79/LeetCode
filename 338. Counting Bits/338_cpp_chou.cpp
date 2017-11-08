// 2017/11/08
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        
        for(int i=0; i<=num; i++){
            int bits = 0, val=i;
            while(val>0){
                if(val%2){
                    bits++;
                }
                val = val >> 1;
            }
            ans.push_back(bits);
        }
        return ans;
    }
};
