class Solution {
public:
    string clearDigits(string s) {
        
        string ans;
        for(char ch:s){

            if(isalpha(ch))
                ans+=ch;
            else
                ans.pop_back();
        }
        return ans;
    }
};