class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();

        int m=matrix[0].size();

       vector<int>dp(m,0);

        int mini=1e9;

        vector<pair<int,int>>dir={{-1,-1},{-1,0},{-1,+1}};

        for(int i=0;i<m;i++){
            dp[i]=matrix[0][i];
        }

        for(int i=1;i<n;i++){
            vector<int>temp(m,-1);
            for(int j=0;j<m;j++){
                int curr_mini=1e9;
                for(int k=0;k<3;k++){
                    int nr = dir[k].first;
                    int nc=dir[k].second;
                    if(j+nc<0||j+nc>m-1) continue;

                    curr_mini=min(dp[j+nc],curr_mini);
                }
                temp[j]=matrix[i][j]+curr_mini;
            }
            dp=move(temp);
        }

        for(int i=0;i<m;i++){
            mini=min(dp[i],mini);
        }
        return mini;
    }
};