class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>indegree(n+2,0);

        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            indegree[u]++;
            indegree[v]++;
        } 

        for(int i=1;i<n+2;i++){
            if(indegree[i]==n) return i;
        }
        return -1;
    }
};