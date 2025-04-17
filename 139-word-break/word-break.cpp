class Solution {
public:
    bool solve(string &s,unordered_set<string>&st,vector<int>&dp,int i){
        if(i>=s.length()) return true;

        if(dp[i]!=-1) return dp[i];
        if(st.find(s)!=st.end()) return true;
        for(int j=1;i+j<=s.length();j++){
             
             string temp=s.substr(i,j);
             if(st.find(temp)!=st.end() && solve(s,st,dp,i+j)) return dp[i]= true;
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.length(),-1);
        unordered_set<string>st;
        for(auto i:wordDict){
            st.insert(i);
        }
        return solve(s,st,dp,0);
    }
};