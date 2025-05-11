class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        long long sum=0;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
        }
        
        
        long long horizontal_sum=0;
        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                horizontal_sum+=grid[i][j];
            }
            if(sum-horizontal_sum==horizontal_sum){
                return true;
            }
        }

        

        long long vertical_sum=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                vertical_sum+=grid[i][j];
            }
            if(sum-vertical_sum==vertical_sum) return true;
        }
        return false;
    }
};