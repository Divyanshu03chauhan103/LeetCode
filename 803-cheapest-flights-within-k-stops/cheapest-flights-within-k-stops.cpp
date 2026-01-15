class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        
        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
        dist[src][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0}); // {cost, node, stops}

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int node = curr[1];
            int stops = curr[2];

            if (node == dst) return cost;
            if (stops > k) continue;

            for (auto &edge : adj[node]) {
                int next = edge.first;
                int newCost = cost + edge.second;

               
                if (newCost < dist[next][stops + 1]) {
                    dist[next][stops + 1] = newCost;
                    pq.push({newCost, next, stops + 1});
                }
            }
        }
        return -1;
    }
};
