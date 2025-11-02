class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        
        // Mark walls
        for (auto& wall : walls) {
            matrix[wall[0]][wall[1]] = -1;
        }

        // Mark guards
        for (auto& guard : guards) {
            matrix[guard[0]][guard[1]] = 1; 
        }

        // Propagate guard influence
        for (auto& guard : guards) {
            int x = guard[0];
            int y = guard[1];

            // Move left
            for (int j = y - 1; j >= 0 && matrix[x][j] != -1 && matrix[x][j] != 1; --j) {
                matrix[x][j] = 2;
            }
            // Move right
            for (int j = y + 1; j < n && matrix[x][j] != -1 && matrix[x][j] != 1; ++j) {
                matrix[x][j] = 2;
            }
            // Move up
            for (int i = x - 1; i >= 0 && matrix[i][y] != -1 && matrix[i][y] != 1; --i) {
                matrix[i][y] = 2;
            }
            // Move down
            for (int i = x + 1; i < m && matrix[i][y] != -1 && matrix[i][y] != 1; ++i) {
                matrix[i][y] = 2;
            }
        }

        // Count unguarded cells
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) { 
                    count++;
                }
            }
        }

        return count;
    }
};

