class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();

        int m= grid[0].size();
        int fresh=0;
        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=2;
                }
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        int result=0;
        vector<vector<int>>dir{{-1,0},{0,1},{1,0},{0,-1}};
        if(fresh==0) return 0;
        while(!q.empty()){

            int N = q.size();
            while(N--){

                pair<int,int>curr = q.front();
                q.pop();
                int i=curr.first;
                int j= curr.second;

                for(auto D:dir){

                    int new_i= i + D[0];
                    int new_j = j + D[1];

                    if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && visited[new_i][new_j]!=2 && grid[new_i][new_j]==1){
                        q.push({new_i,new_j});
                        visited[new_i][new_j]=2;
                        fresh--;
                    }
                }
                
            }
            result++;
        }

        return fresh==0? result-1:-1;
    }
};