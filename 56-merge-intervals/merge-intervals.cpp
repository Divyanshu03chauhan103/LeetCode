class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();

        if (n == 0) return result; 

       
        sort(intervals.begin(), intervals.end());

        int i = 0;
        while (i < n) {
            int a = intervals[i][0];
            int b = intervals[i][1];
            int j = i + 1;

          
            while (j < n && intervals[j][0] <= b) {  
                b = max(b, intervals[j][1]);
                j++;
            }

           
            result.push_back({a, b});
            i = j; 
        }
        return result;
    }
};
