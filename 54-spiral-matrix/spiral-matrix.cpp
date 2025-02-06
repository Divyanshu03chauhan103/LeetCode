class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }
        int top = 0;
        int left = 0;
        int right = matrix[0].size() - 1;  // Corrected line
        int down = matrix.size() - 1;
        int id = 0;
        while (top <= down && left <= right) {

            if (id == 0) {
                for (int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            else if (id == 1) {
                for (int i = top; i <= down; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            else if (id == 2) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[down][i]);
                }
                down--;
            }
            else if(id==3) {
                for (int i = down; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            id = (id + 1) % 4;
        }
        return result;
    }
};
