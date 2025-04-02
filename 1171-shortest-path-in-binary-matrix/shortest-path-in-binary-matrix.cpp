class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        queue<pair<int,pair<int,int>>>q;
        if(grid[0][0]!=0) return -1;

            q.push({1,{0,0}});
        
        int n =grid.size();
        int m=grid[0].size();

        vector<vector<int>>distance(n,vector<int>(m,1e9));
        int Drow[]={-1,0,+1,0,-1,+1,+1,-1};
        int Dcol[]={0,+1,0,-1,+1,+1,-1,-1};
        distance[0][0]=1;

        while(!q.empty()){

            int row=q.front().second.first;
            int col=q.front().second.second;
            int dis=q.front().first;
            q.pop();
            if(row==n-1 && col==m-1) return dis;
            for(int i=0;i<8;i++){
                int new_row=row+Drow[i];
                int new_col=col+Dcol[i];
                
                if(new_row>=0 && new_row<n&& new_col>=0&&new_col<m && grid[new_row][new_col]==0 && dis+1<distance[new_row][new_col]){

                    if(new_row==n-1 && new_col==m-1) return dis+1;

                    distance[new_row][new_col]=dis+1;

                    q.push({dis+1,{new_row,new_col}});
                } 
            }
        }
        return -1;
    }
};