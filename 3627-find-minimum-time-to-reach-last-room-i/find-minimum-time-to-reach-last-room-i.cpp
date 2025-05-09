class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        int dr[] = {+0,+1,+0,-1};
        int dc[]={+1,+0,-1,+0};
        
        pq.push({0,0,0});

        int n=moveTime.size();

        int m= moveTime[0].size();

         vector<vector<int>>visited(n,vector<int>(m,0));
         visited[0][0] =1;
    
        while(!pq.empty()){

            auto state = pq.top();
            int t = state[0];
            int r = state[1];
            int c = state[2];
            
            for(int i=0;i<4;i++){

                int new_r = r+dr[i];
                int new_c = c+dc[i];
                if(new_r == n - 1 && new_c == m - 1) {
                     if(t>=moveTime[new_r][new_c]) return t+1;
                     else return moveTime[new_r][new_c]+1;
                }
                if(new_r < n && new_r>=0 && new_c<m && new_c>=0 && visited[new_r][new_c]==0){
                    if(t<moveTime[new_r][new_c])
                        pq.push({moveTime[new_r][new_c]+1,new_r,new_c});
                    else 
                        pq.push({t+1,new_r,new_c});

                    visited[new_r][new_c]=1;
                }
            }
            pq.pop();
        }
            return -1;
    }
};