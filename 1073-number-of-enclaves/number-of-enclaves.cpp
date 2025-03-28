class Solution {
public:
    void bfs(vector<vector<int>>&visited,vector<vector<int>>grid,int row,int col,int Drow[],int Dcol[]){

        queue<pair<int,int>>q;
        q.push({row,col});
        visited[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int curr_row=q.front().first;
            int curr_col= q.front().second;

            for(int i=0;i<4;i++){
                int new_row=curr_row+Drow[i];
                int new_col=curr_col+Dcol[i];

                if(new_row>=0&& new_row<n && new_col>=0 && new_col<m && grid[new_row][new_col] && !visited[new_row][new_col]){
                    q.push({new_row,new_col});
                    visited[new_row][new_col]=1;
                }
            }
            q.pop();
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));
        int Drow[] = {0,+1,0,-1};
        int Dcol[] = {+1,0,-1,0};
        for(int i=0;i<m;i++){
            if(grid[0][i]==1)
                bfs(visited,grid,0,i,Drow,Dcol);
            if(grid[n-1][i]==1)
                bfs(visited,grid,n-1,i,Drow,Dcol);
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1)
                bfs(visited,grid,i,0,Drow,Dcol);
            if(grid[i][m-1]==1)
                bfs(visited,grid,i,m-1,Drow,Dcol);
        }

        int count =0;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j])
                    count++;
                    
            }
        }
        return count;
    }
};