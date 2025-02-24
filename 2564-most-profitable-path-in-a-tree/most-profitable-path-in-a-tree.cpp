class Solution {
public:

    //DFS for Bob's traversal which will fill the BobTime , for tracking its time of reaching on the particular node
    bool DFSBob(unordered_map<int,int>&BobTime,int time,vector<bool>&visited,int bob,unordered_map<int,vector<int>>&adj){

        visited[bob] = true;

        BobTime[bob] = time;
        
        if(bob==0) return true;

        for(auto i : adj[bob]){
            if(!visited[i]){
                if(DFSBob(BobTime,time+1,visited,i,adj))   return true;
            }
        }

        BobTime.erase(bob);

        return false;
    }
    //DFS for alice traversal which will calculate the result
    void alice(int &result,int ans,vector<int>&amount,vector<bool>&visited,int curr,unordered_map<int,vector<int>>&adj,unordered_map<int,int>&BobTime,int t){

        visited[curr]=true;

        if(BobTime.find(curr)==BobTime.end() || BobTime[curr]>t)
            ans+=amount[curr];

        else if(BobTime[curr]==t)
            ans+=amount[curr]/2;
        
        if(adj[curr].size()==1 && curr!=0)
            result=max(result,ans);

        for(auto &nbr : adj[curr]){
            if(!visited[nbr])
                alice(result,ans,amount,visited,nbr,adj,BobTime,t+1);
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        //adj matrix to make the graph
        unordered_map<int,vector<int>>adj;

        unordered_map<int,int>BobTime;

        int n= amount.size();
        
        vector<bool>visited(n,false);

        for(auto i: edges){

            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        DFSBob(BobTime,0,visited,bob,adj);

        int result=INT_MIN;

        visited.assign(n,false);
        alice(result,0,amount,visited,0,adj,BobTime,0);

        return result;
    }
};