class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int repeating=-1;
        int sum=0;
        vector<bool>visited(2501,false);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    if(!visited[grid[i][j]]){
                        sum+=grid[i][j];
                        visited[grid[i][j]]=true;
                    }
                    else
                        repeating = grid[i][j];
                
            }
        }

        int N= n*n;

        int missing= N*(N+1)/2-sum;
        return {repeating,missing};
    }
};