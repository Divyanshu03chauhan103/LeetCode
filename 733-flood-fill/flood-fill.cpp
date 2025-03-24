class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<int> delr = {-1, 0, +1, 0};
        vector<int> delc = {0, +1, 0, -1};
        int iniColor = image[sr][sc];

        
            dfs(image, sr, sc, color, iniColor, delr, delc);
        
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int iniColor,
             const vector<int>& delr, const vector<int>& delc) {
        
        image[sr][sc] = color;  

        int n = image.size();
        int m = image[0].size();
        
        for (int i = 0; i < 4; i++) {
            int newRow = sr + delr[i];
            int newCol = sc + delc[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                image[newRow][newCol] == iniColor && image[newRow][newCol]!=color) {
                dfs(image, newRow, newCol, color, iniColor, delr, delc);
            }
        }
    }
};
