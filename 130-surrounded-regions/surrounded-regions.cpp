class Solution {

private:
    void dfs(int row,int col,vector<vector<int>>&visited,vector<vector<char>>&board,int Drow[],int Dcol[]){

        visited[row][col]=1;

        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<4;i++){

            int nrow=row+Drow[i];
            int ncol=col+Dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && board[nrow][ncol]=='O')
                dfs(nrow,ncol,visited,board,Drow,Dcol);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));

        int Drow[] = {0,+1,0,-1};
        int Dcol[] = {+1,0,-1,0};
        for(int i=0;i<m;i++){
            if(board[0][i]=='O')
                dfs(0,i,visited,board,Drow,Dcol);
            
            if(board[n-1][i]=='O'){
                dfs(n-1,i,visited,board,Drow,Dcol);
            }
        }


        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
                dfs(i,0,visited,board,Drow,Dcol);
            
            if(board[i][m-1]=='O')
                dfs(i,m-1,visited,board,Drow,Dcol);
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j])
                    board[i][j] = 'X';
            }
        }
 
    }
};