% 2017/11/02 Peony
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        vector<string>::iterator item;
        vector<int> table = {1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2};
        vector<int> tcount;
        result.clear();
       
        for(int i = 0; i<words.size(); i++){
            string word = words[i];
            tcount.clear();
            for(int j = 0; j < word.size(); j++){
                if(islower(word[j])){
                    tcount.push_back(table[word[j]-'a']);
                }else{
                    tcount.push_back(table[word[j]-'A']);
                }
            }
            
            if((unique(tcount.begin(), tcount.end()) - tcount.begin())==1){
                result.push_back(word);
            }
        }
        
        
        return result;    
    }
    
};
