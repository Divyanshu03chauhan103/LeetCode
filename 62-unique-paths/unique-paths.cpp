class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,dp,m,n);
    }

    int solve(int i,int j ,vector<vector<int>>&dp,int m,int n){

        if(i>=m||j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = solve(i+1,j,dp,m,n);
        int right=solve(i,j+1,dp,m,n);
        return dp[i][j]=down+right;
    }
};