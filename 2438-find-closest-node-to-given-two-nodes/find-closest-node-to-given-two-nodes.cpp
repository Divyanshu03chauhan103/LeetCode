class Solution {
public:
    void bfs(const vector<int>& edges, int start, vector<int>& dist) {
        int n = edges.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            int next = edges[node];
            if (next != -1 && !visited[next]) {
                dist[next] = dist[node] + 1;
                visited[next] = true;
                q.push(next);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);

        int answer = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    answer = i;
                }
            }
        }

        return answer;
    }
};
