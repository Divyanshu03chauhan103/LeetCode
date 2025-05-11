class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m= obstacleGrid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0 )
                    if(obstacleGrid[0][0]==1) dp[0][0]=0;
                    else dp[0][0]=1;
                else{
                    int up = 0;
                    int left=0;
                    if(i>0){
                        if(obstacleGrid[i-1][j]==1) up=0;
                        else up=dp[i-1][j];
                    }
                    if(j>0){
                        if(obstacleGrid[i][j-1]==1) left=0;
                        else left=dp[i][j-1];
                    }
                    if(obstacleGrid[i][j]==1) dp[i][j]=0;
                    else dp[i][j]=left+up;
                }
            }
        }
        return dp[n-1][m-1];
    }
};