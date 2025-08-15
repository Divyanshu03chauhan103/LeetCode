class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);

        for(vector<int>i:prerequisites){
            int v=i[0];
            int u=i[1];
            indegree[v]++;
            adj[u].push_back(v);
        }

        int count=0;
        queue<int>q;
        vector<int>result;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                count++;
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            result.push_back(u);

            for(int v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }
        return count == numCourses ? result : vector<int>();

    }
};