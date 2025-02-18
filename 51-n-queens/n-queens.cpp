class Solution {
public:
   
    int N;
    bool isvalid(int row,int col,vector<string>Board){

        for(int i=row-1;i>=0;i--){
            if(Board[i][col]=='Q')
                return false;
        }

        for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--)
            if(Board[i][j]=='Q')
                return false;
        
        for(int i=row-1,  j=col+1;i>=0 && j<N;i--,j++)
            if(Board[i][j]=='Q')
                return false;

        return true;
    }
    
    void solve( vector<vector<string>>&result,vector<string>Board,int row){

        if(row>=N) {

            result.push_back(Board);
            return;
        } 

        for(int i=0;i<N;i++){

            if(isvalid(row,i,Board))
                {
                    Board[row][i]='Q';
                    solve(result,Board,row+1);
                    Board[row][i]='.';
                }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        if(n==0) return {};
         vector<vector<string>>result;
        N=n;
     vector<string>Board(n,string(n,'.'));
        solve(result,Board,0);
     return result;   
    }
};