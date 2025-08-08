class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {

        int n=fruits.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));   
        
        int child1=0;
        for(int i=0;i<n;i++){
            child1+=fruits[i][i];
        }

        int child2= solveChild2(0,n-1,fruits,dp);

        int child3=solveChild3(n-1,0,fruits,dp);

        return child1+child2+child3;
        
    }

    int solveChild2(int i,int j,vector<vector<int>>&fruits,vector<vector<int>>&dp){

        if(j<0 || j>=fruits.size() || i>=fruits.size()) return 0;

        if(i==j || i>j) return 0;

        if(i==fruits.size()-1 && j==fruits.size()-1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int path1=fruits[i][j]+solveChild2(i+1,j-1,fruits,dp);
        int path2=fruits[i][j]+solveChild2(i+1,j,fruits,dp);
        int path3=fruits[i][j]+solveChild2(i+1,j+1,fruits,dp);

        return dp[i][j]= max({path1,path2,path3});
    }
    int solveChild3(int i,int j,vector<vector<int>>&fruits,vector<vector<int>>&dp){

        if(i<0 || j>=fruits.size() || i>=fruits.size()) return 0;
        if(i==fruits.size()-1 && j==fruits.size()-1) return 0;
        if(i==j || i<j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int path1=fruits[i][j]+solveChild3(i-1,j+1,fruits,dp);
        int path2=fruits[i][j]+solveChild3(i,j+1,fruits,dp);
        int path3=fruits[i][j]+solveChild3(i+1,j+1,fruits,dp);

        return dp[i][j]= max({path1,path2,path3});
    }
};