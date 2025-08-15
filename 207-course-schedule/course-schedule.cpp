class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);

        vector<int>indegree(numCourses);

        for(vector<int>i:prerequisites){
            int v=i[0];
            int u=i[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        int count=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    count++;
                    q.push(v);
                }
            }
        }
        return count==numCourses;
    }
};