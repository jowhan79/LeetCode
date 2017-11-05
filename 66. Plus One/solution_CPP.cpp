// 2017/11/05 Jowhan

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans=digits;
        int carry=0, i=digits.size()-1;
        
        do{
            if( ++ans[i]==10 ){
                ans[i] = 0;
                carry = 1;
            }
            else
                carry = 0;
            --i;
        }while(carry!=0 && i>=0);
        
        if(carry==1)
            ans.insert(ans.begin(),1);
        
        return ans;
    }
};
