class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(vector<int>i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
            indegree[i[1]]++;

        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1)
                q.push(i);
        }
        int nodes=n;
        while(nodes>2){
            int N=q.size();
            for(int i=0;i<N;i++){
                int curr=q.front();
                q.pop();

                for(int i:adj[curr]){
                    indegree[i]--;
                    if(indegree[i]==1) q.push(i);
                }
            }
            nodes-=N;
        }

        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};