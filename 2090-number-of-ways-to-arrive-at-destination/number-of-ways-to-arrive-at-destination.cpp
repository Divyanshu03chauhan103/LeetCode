class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>>graph(n);

        for(auto i:roads){

            graph[i[0]].push_back({i[1],i[2]});
            graph[i[1]].push_back({i[0],i[2]});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;

        pq.push({0,0});
        vector<long long>distance(n,LLONG_MAX);
        vector<int>ways(n,0);
        ways[0]=1;
        distance[0]=0;  
        int mod=(int)1e9+7;    
        while(!pq.empty()){

            int node=pq.top().second;
            long long dis=pq.top().first;

            pq.pop();
            
            for(auto i:graph[node]){
                int new_node=i.first;
                int edge_len=i.second;

                if(dis+edge_len<distance[new_node]){
                    distance[new_node]=(dis+edge_len);
                    ways[new_node]=ways[node];
                    pq.push({distance[new_node],new_node});
                }
                else if( dis+edge_len==distance[new_node]){
                    ways[new_node]=(ways[new_node]+ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};