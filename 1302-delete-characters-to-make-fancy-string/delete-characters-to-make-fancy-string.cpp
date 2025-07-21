class Solution {
public:
    string makeFancyString(string s) {
        string result(1,s[0]);

        int count=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1] && count<2){
                count++;
                result.push_back(s[i]);
            } 
            else if(s[i]!=s[i-1]){
                count=1;
                result.push_back(s[i]);
            }
        }
        return result;
    }
};