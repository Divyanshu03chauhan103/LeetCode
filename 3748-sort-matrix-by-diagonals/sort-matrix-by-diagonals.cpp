class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }

        for(auto &[key,diag]:mp){

            if(key>=0)
                sort(diag.begin(),diag.end(),greater<int>());
            else sort(diag.begin(),diag.end());
        }

        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                grid[i][j]=mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return grid;
    }
};