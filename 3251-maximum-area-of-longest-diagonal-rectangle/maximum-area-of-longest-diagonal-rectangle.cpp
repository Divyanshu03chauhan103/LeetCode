class Solution {
public:
    int diagonal_length(int l, int w) {
        return l * l + w * w; 
    }

    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int diagonal = -1;
        int area = 0;

        for (int i = 0; i < dimensions.size(); i++) {
            int diag = diagonal_length(dimensions[i][0], dimensions[i][1]);
            int rectArea = dimensions[i][0] * dimensions[i][1];

            if (diag > diagonal) {
                diagonal = diag;       
                area = rectArea;       
            } 
            else if (diag == diagonal && rectArea > area) {
                area = rectArea;       
            }
        }
        return area;
    }
};
