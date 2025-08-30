class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if (n != m || n != 9 || m != 9) return false;

        for (int i = 0; i < 9; i++) {
            vector<int> row(10, 0);
            vector<int> col(10, 0);
            vector<int> grid(10, 0);

            // check row
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (row[num]) return false;
                    row[num] = 1;
                }
            }

            // check column
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    int num = board[j][i] - '0';
                    if (col[num]) return false;
                    col[num] = 1;
                }
            }

            // check 3x3 grid
            int startRow = (i / 3) * 3;
            int startCol = (i % 3) * 3;
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    char ch = board[startRow + r][startCol + c];
                    if (ch != '.') {
                        int num = ch - '0';
                        if (grid[num]) return false;
                        grid[num] = 1;
                    }
                }
            }
        }
        return true;
    }
};
