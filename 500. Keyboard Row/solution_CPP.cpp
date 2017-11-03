class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        vector<string> key = {"QWERTYUIOP","ASDFGHJKL","ZXCVBNM"};
        int i, j, row;
        bool is_legal;        
        
        for( i=0; i<words.size(); ++i ){
            is_legal = 1;
            // first character: assign nth row
            for( j=0; j<key.size(); ++j ){
                if( key[j].find(toupper(words[i][0]))!=-1 ){
                    row = j;
                    break;
                }
            }
            // remain charactors: should have same row with the first character
            for( j=1; j<words[i].length(); ++j ){
                if( key[row].find(toupper(words[i][j]))==-1 ){
                    is_legal = 0;
                    break;
                }
            }
            // all charactors are from same row: record in ans
            if( is_legal ){
                ans.push_back(words[i]);
            }
        }               
        
        return ans;
    }  
};
