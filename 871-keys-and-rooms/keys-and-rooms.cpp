class Solution {
public:
    void dfs(vector<vector<int>>&rooms,vector<int>&visited,int node){

        visited[node]=1;

        for(auto new_node:rooms[node]){
            if(visited[new_node]==1) continue;

            dfs(rooms,visited,new_node);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int  n = rooms.size();
        vector<int>visited(n,0);

        dfs(rooms,visited,0);

        for(auto i:visited){
            if(i==0){
                
                return 0;
            } 
        }
        return 1;
    }
};