class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result=0;

        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]=='1'){
                    dfs(visited,dir,grid,i,j,n,m);
                    result++;
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<int>>&visited,vector<vector<int>>&dir,vector<vector<char>>&grid,int i,int j,int n,int m){

        visited[i][j]=1;

        for(vector<int> d:dir){
            
            int new_i=i+d[0];
            int new_j=j+d[1];

            if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && grid[new_i][new_j]=='1'&& !visited[new_i][new_j]){
                dfs(visited,dir,grid,new_i,new_j,n,m);
            }
        }
    }
};