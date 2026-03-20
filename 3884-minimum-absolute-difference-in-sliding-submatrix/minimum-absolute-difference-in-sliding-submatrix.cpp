class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>ans(m - k + 1,vector<int>(n - k + 1,0));
        vector<int>v(k*k);
        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                v.clear();
                for(int a=i;a<i+k;a++){
                    for(int b = j ; b < j + k ; b++){
                        v.push_back(grid[a][b]);
                    }
                }

                sort(v.begin(),v.end());
                auto it = unique(v.begin(),v.end());

                v.erase(it,v.end());

                if(v.size()<2){
                    ans[i][j]=0;
                }else{
                    int minDiff=INT_MAX;
                    for(int ind = 0 ; ind < v.size() - 1 ;ind++ ){
                        minDiff=min(minDiff,v[ind+1]-v[ind]);
                    }
                    ans[i][j]=minDiff;
                }

            }
        }
        return ans;
    }
};