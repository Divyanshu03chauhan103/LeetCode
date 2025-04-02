class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // Min-Heap to store {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        vector<vector<int>> difference(n, vector<int>(m, 1e9));
        difference[0][0] = 0;

        // 4 possible movement directions
        int drow[] = {+1, 0, -1, 0};
        int dcol[] = {0, +1, 0, -1};

        q.push({0, {0, 0}});

        while (!q.empty()) {
            int diff = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();

            // If we reached the destination, return the minimum effort
            if (row == n - 1 && col == m - 1) return diff;

            for (int i = 0; i < 4; i++) {
                int new_row = row + drow[i];
                int new_col = col + dcol[i];

                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m) {
                    int new_effort = max(abs(heights[row][col] - heights[new_row][new_col]), diff);
                    
                    if (new_effort < difference[new_row][new_col]) {
                        difference[new_row][new_col] = new_effort;
                        q.push({new_effort, {new_row, new_col}});
                    }
                }
            }
        }
        return -1;
    }
};
