class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &i : prerequisites) {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++; 
        }

        queue<int> q;
        vector<int> order;

   
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

     
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for (auto i : adj[node]) {
                indegree[i]--;
                if (indegree[i] == 0) q.push(i);
            }
        }

        if(order.size()!=numCourses) return {};
        return order;
    }
};