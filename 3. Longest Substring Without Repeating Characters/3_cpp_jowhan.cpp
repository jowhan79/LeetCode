// 2017/11/09 Jowhan

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> char_index(256,-1);
        int max_substr_length=0, i, substr_begin=0;
        
        for( i=0; i<s.length(); ++i ){
            substr_begin = max(substr_begin, char_index[s[i]]+1);
            char_index[s[i]] = i;
            max_substr_length = max(max_substr_length, i-substr_begin+1);
        }
        
        return max_substr_length;
    }
};
