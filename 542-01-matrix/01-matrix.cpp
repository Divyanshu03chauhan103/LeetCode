class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue<vector<int>>q;

        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>dis(m,vector<int>(n,0));

        vector<vector<int>>visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    visited[i][j]=1;
                }
            }
        }

        vector<vector<int>>dir= {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){

            vector<int>curr=q.front();
            int i=curr[0];
            int j=curr[1];
            int D=curr[2];
            q.pop();
            dis[i][j]=D;
            for(vector<int>d:dir){
                int new_i=i+d[0];
                int new_j=j+d[1];

                if(new_i>=0 && new_j>=0 && new_i<m && new_j<n && !visited[new_i][new_j]) {
                    q.push({new_i,new_j,D+1});
                    visited[new_i][new_j]=1;
                }
            }

        }

        return dis;
    }
};