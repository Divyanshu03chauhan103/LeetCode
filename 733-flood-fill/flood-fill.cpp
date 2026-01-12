class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        queue<pair<int,int>>q;
        int m=image.size();
        int n=image[0].size();
        q.push({sr,sc});
        vector<vector<int>>dir={
            {0,+1},{0,-1},{+1,0},{-1,0}
        };
        int starting_color=image[sr][sc];
        vector<vector<int>>visited(m,vector<int>(n,0));
        visited[sr][sc]=1;
        while(!q.empty()){

        
                
                pair<int,int>curr=q.front();
                int i=curr.first;
                int j=curr.second;
                image[i][j]=color;
                q.pop();

                for(auto d:dir){
                    int new_i=i+d[0];
                    int new_j=j+d[1];
                    if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && !visited[new_i][new_j] && image[new_i][new_j]==starting_color){
                        q.push({new_i,new_j});
                        visited[new_i][new_j]=1;
                    }
                        
                }
            }
        
        return image;
    }
};