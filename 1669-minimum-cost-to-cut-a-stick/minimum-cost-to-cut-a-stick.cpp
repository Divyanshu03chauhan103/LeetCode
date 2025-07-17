class Solution {
public:
    int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j) return 0;

        int mini=1e9+7;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int ind=i;ind<=j;ind++){
            int curr_cost=cuts[j+1]-cuts[i-1]+solve(i,ind-1,cuts,dp)+solve(ind+1,j,cuts,dp);
            mini=min(mini,curr_cost);
        }
        return dp[i][j]= mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(begin(cuts),end(cuts));
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return solve(1,c,cuts,dp);
    }
};