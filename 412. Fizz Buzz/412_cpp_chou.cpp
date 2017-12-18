// 2017/12/18 Peony
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> ans;
        ans.clear();
        string str;
        for(int i = 1; i<=n; i++){
            str = "";
            if( i % 3 == 0 ){
                str += "Fizz";
            }
            if( i % 5 == 0){
                str += "Buzz";
            }
            if( i % 3 != 0 && i % 5 != 0){
                str = int2str(i);
            }
            ans.push_back(str);
        }
        return ans;  
    }
private:
    string int2str(int n){
        string s;
        stringstream ss(s);
        ss << n;
        return ss.str();
    }
};
