class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build the graph
        vector<vector<pair<int, int>>> graph(n);
        for (auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]}); // {destination, price}
        }
        
        // BFS approach with queue
        queue<vector<int>> q;
        q.push({0, src, 0}); // {price, node, stops}
        
        // Track the minimum price to reach each node
        vector<int> minPrice(n, INT_MAX);
        minPrice[src] = 0;
        
        int result = INT_MAX;
        
        while (!q.empty()) {
            vector<int> current = q.front();
            q.pop();
            
            int price = current[0];
            int node = current[1];
            int stops = current[2];
            
            // If destination reached, update result
            if (node == dst) {
                result = min(result, price);
                continue;
            }
            
            // If we've used all allowed stops, don't explore further
            if (stops > k) continue;
            
            // Explore neighbors
            for (auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                int edgePrice = neighbor.second;
                int newPrice = price + edgePrice;
                
                // Only proceed if the new price is better than the best known result
                // and we haven't exceeded stops
                if (newPrice < result && stops <= k) {
                    // We only need to visit a node again if we can do it with fewer stops
                    // or with a cheaper price
                    if (newPrice < minPrice[nextNode]) {
                        minPrice[nextNode] = newPrice;
                        q.push({newPrice, nextNode, stops + 1});
                    }
                }
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};