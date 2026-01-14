class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int r=heights.size();
        int c=heights[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;

        vector<vector<int>>diff(r,vector<int>(c,1e9));
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};

        diff[0][0]=0;

        q.push({0,0,0});
        while(!q.empty()){
            vector<int>curr=q.top();
            int dis=curr[0];
            int curr_r=curr[1];
            int curr_c=curr[2];
            
            q.pop();
            if(curr_r==r-1 && curr_c==c-1) return dis;
            for(vector<int>i:dir){
                int new_r=curr_r+i[0];
                int new_c=curr_c+i[1];
                if(new_r>=0 && new_c>=0 && new_c<c && new_r<r){
                    int effort = max(abs(heights[curr_r][curr_c]-heights[new_r][new_c]),dis);
                    if(effort<diff[new_r][new_c]){
                        diff[new_r][new_c]=effort;
                        q.push({effort,new_r,new_c});
                    }
                }
            }
        }
        return -1;
    }
};