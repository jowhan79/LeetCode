// 2017/11/10 Jowhan

class Solution {
public:
    string longestPalindrome(string s) {
        return _longestPalindrome_solution2(s);
    }    
    
private:
    /********************** solution 1 **********************/
    // dp solution: time: O(n^2), space: O(n^2)
    
    inline string _longestPalindrome_solution1(string s) {
        int s_len=s.length(), sub_len, head, max_length=1, max_head=0;
        // declare 2D vector
        vector<vector<bool>> isPalindrome;
        isPalindrome.resize(s_len,vector<bool>(s_len));  
        
        // for substring length = 2 or 3: only need to check head and tail
        for( sub_len=1; sub_len<3; ++sub_len ){  // sub_len = length-1
            for( head=0; head+sub_len<s_len; ++head ){
                if( s[head]==s[head+sub_len] ){
                    isPalindrome[sub_len][head] = 1;
                    max_length = sub_len+1;
                    max_head = head;
                }
            }
        }
        
        // for substring length >= 4 : need to check middle and head and tail
        for( sub_len=3; sub_len<s_len; ++sub_len ){  // sub_len = length-1
            for( head=0; head+sub_len<s_len; ++head ){
                if( isPalindrome[sub_len-2][head+1] && s[head]==s[head+sub_len] ){
                    isPalindrome[sub_len][head] = 1;
                    max_length = sub_len+1;
                    max_head = head;
                }
            }
        }
        
        return s.substr(max_head,max_length);
    }
    /********************************************************/
    
    
    /********************** solution 2 **********************/
    // greedy solution: time: O(n^2), space: O(1)
    // ...原來這題不用DP，硬要用DP得到糞解QQ
    // 關鍵: 讓原字串每個字元都當中心一次，頭與尾若相同就延伸。
    // 小技巧: 碰到重複字元可跳過選中心，以重複字元之字串當中心即可。
    
    inline string _longestPalindrome_solution2(string s) {
        size_t s_len=s.length();
        if( s_len==0 ) return s;
        
        size_t head, mid, tail, max_length=0, max_head;
        
        // early stop if found substring is longer than remain possible length 
        for( mid=0; mid<s_len && max_length<=(s_len-mid)*2; ){
            
            // start from center
            head = tail = mid;
            
            // tail go ahead if meet duplicate charactor
            for( ; tail<s_len-1 && s[tail]==s[tail+1]; ++tail );
            
            // set mid to next non-duplicate charactor
            mid = tail + 1;
            
            // try to extend palindrome
            for( ; head>0 && tail<s_len-1 && s[head-1]==s[tail+1]; --head, ++tail );
            
            // record best
            if( max_length<tail-head+1 ){
                max_length = tail-head+1;
                max_head = head;
            }
        }
        
        return s.substr(max_head, max_length);
    }    
    /********************************************************/
};
