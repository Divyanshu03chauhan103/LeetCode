class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){

                if(i==n-1 && j==i-1) dp[i][j]=triangle[i][j];
                else{
                    int nrsc = 0;
                    int nrnc =0;
                    
                    if(i<n-1 ) nrnc = dp[i+1][j+1];
                    if(i<n-1 ) nrsc = dp[i+1][j];
                    
                    dp[i][j]=triangle[i][j]+min(nrnc,nrsc);
                   
                }
            }
        }
        return dp[0][0];

    }
};