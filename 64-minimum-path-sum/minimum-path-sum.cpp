class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){

                if(i==n-1 && j==m-1) dp[i][j]=grid[i][j];
                else{
                    int right=INT_MAX;
                    int down=INT_MAX;
                    if(i<n-1) down = dp[i+1][j];
                    if(j<m-1) right=dp[i][j+1];

                    dp[i][j]=grid[i][j]+min(down,right);
                }
            }
        }
        return dp[0][0];
    }
};
