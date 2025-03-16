class Solution {
public:
    string reverseWords(string s) {
        vector<string>sample;

        for(int i=0;i<s.length();i++){
            string curr="";
            while(isalnum(s[i]) && i<s.length()){
                curr+=s[i];
                i++;
            }

            if(!curr.empty()){
                sample.push_back(curr);
            }
        }
        int n=sample.size();
        string result = "";
        for(int i=n-1;i>=0;i--){
            
            result += sample[i] + " ";
        }

        return result.substr(0,result.length()-1);
    }
};