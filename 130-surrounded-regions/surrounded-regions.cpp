class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int n=board[0].size();
        int m = board.size();
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>>visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(visited,board,i,0,dir);
            
            if(board[i][n-1]=='O') dfs(visited,board,i,n-1,dir);
        }

        for(int i=0;i<n;i++){
            if(board[0][i]=='O') dfs(visited,board,0,i,dir);
            if(board[m-1][i]=='O') dfs(visited,board,m-1,i,dir);
        }

          for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && visited[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<int>>&visited,vector<vector<char>>&board,int i,int j,vector<vector<int>>&dir){
        visited[i][j]=1;

        for(vector<int>d:dir){
            int new_i=i+d[0];
            int new_j=j+d[1];

            if(new_i>=0 && new_j>=0 && new_i<board.size() && new_j<board[0].size() && !visited[new_i][new_j] && board[new_i][new_j]=='O'){
                dfs(visited,board,new_i,new_j,dir);
            }
        }
    }
};