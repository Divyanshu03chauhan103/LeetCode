class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0]!=0) return -1;

        int r=grid.size();
        int c=grid[0].size();

        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

        vector<vector<int>>distance(r,vector<int>(c,0));
        queue<vector<int>>q;
        q.push({0,0,1});

        distance[0][0]=1;
        while(!q.empty()){

            vector<int>curr = q.front();
            q.pop();
            int curr_r=curr[0];
            int curr_c=curr[1];
            int curr_dis=curr[2];

            if(curr_r == r-1 && curr_c==c-1) return curr_dis;

            for(auto i:dir){
                int new_r=curr_r+i[0];
                int new_c=curr_c+i[1];

                if(new_r>=0 && new_c>=0 && new_r<r && new_c<c && !distance[new_r][new_c] && grid[new_r][new_c]==0){
                     if(new_r==r-1 && new_c==c-1 ) return curr_dis+1;
                    q.push({new_r,new_c,curr_dis+1});
                    distance[new_r][new_c]=1;

                }
            }
        }
        return -1;
    }
};