class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<pair<int,int>>>graph(n);

        for(int i=0;i<redEdges.size();i++){
            graph[redEdges[i][0]].push_back({redEdges[i][1],0});
        }
        for(int i=0;i<blueEdges.size();i++){
            graph[blueEdges[i][0]].push_back({blueEdges[i][1],1});
        }

        vector<int>distance(n,-1);
        vector<vector<bool>>visited(n,vector<bool>(2,false));
        queue<vector<int>>q;
        q.push({0,0,-1});

        distance[0]=0;

        while(!q.empty()){

            auto i=q.front();
            q.pop();
            int color=i[2];
            int node=i[1];
            int dis=i[0];

            for(auto i:graph[node]){
                int new_node=i.first;
                int new_color=i.second;

                if(new_color!=color && !visited[new_node][new_color]){
                    
                    visited[new_node][new_color]=true;
                    q.push({dis+1,new_node,new_color});
                    if(distance[new_node]==-1)
                        distance[new_node] = dis + 1;

                }
            }
        }
        return distance;
    }
};