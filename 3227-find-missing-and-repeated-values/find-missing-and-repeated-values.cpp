class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        set<int>s;
        int n=grid.size();
        int repeating=-1;
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(s.count(grid[i][j])){
                    repeating=grid[i][j];
                }
                else{
                    sum+=grid[i][j];
                    s.insert(grid[i][j]);
                }
            }
        }

        int N= n*n;

        int missing= N*(N+1)/2-sum;

        return {repeating,missing};
    }
};