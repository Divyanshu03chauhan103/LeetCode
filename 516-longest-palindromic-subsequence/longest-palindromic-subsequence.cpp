const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<int>prev(n+1,0),curr(n+1,0);
        string s2 = s;
        reverse(begin(s2),end(s2));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    if(s[i-1]==s2[j-1])  curr[j]=1+prev[j-1];

                    else curr[j] = max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        
        return curr[n];
    }
};