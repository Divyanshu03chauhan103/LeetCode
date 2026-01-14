class Solution {
public:
     bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        
        
        vector<int>indegree(V,0);
        
        for(int i=0;i<V;i++){
            for(int v:adj[i]){
                indegree[v]++;
            }
        }
        
        queue<int>q;
        int topo_size=0;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
      
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            topo_size++;
            
            for(int i:adj[curr]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        
        
        return topo_size==V;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return isCyclic(numCourses,prerequisites);
    }
};