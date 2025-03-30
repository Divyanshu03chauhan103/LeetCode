class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>graphRev(n);
        vector<int> indegree(n, 0);

        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                graphRev[j].push_back(i);
                indegree[i]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        vector<int>safeNodes;
        while(!q.empty()){

            int node=q.front();
            safeNodes.push_back(node);
            q.pop();

            for(int i:graphRev[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }

        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};