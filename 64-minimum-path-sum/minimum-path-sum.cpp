class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j,int m,int n, vector<vector<int>>&dp){

        if(i==n-1 && j==m-1) return grid[i][j];

        if(i<0 || j<0 || i>n-1 || j>m-1) return 999999;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=grid[i][j]+solve(grid,i,j+1,m,n,dp);
        int down=grid[i][j]+solve(grid,i+1,j,m,n,dp);
        return dp[i][j]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid[0].size();
        int n=grid.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

       
        return solve(grid,0,0,m,n,dp);
    }
};