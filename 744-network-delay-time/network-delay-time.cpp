class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>graph(n+1);

        for(auto i:times){
            graph[i[0]].push_back({i[1],i[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


        pq.push({0,k});
        vector<int>distance(n+1,1e9);
        distance[k]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto i:graph[node]){
                int new_node=i.first;
                int edge=i.second;
                if(dis+edge<distance[new_node]){
                    distance[new_node]=dis+edge;
                    pq.push({dis+edge,new_node});
                }
            }
        }

        int result=*max_element(distance.begin()+1,distance.end());
        
        return result==1e9?-1:result;
    }
};