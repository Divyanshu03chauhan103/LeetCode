class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>result;
        sort(intervals.begin(),intervals.end());

        int n=intervals.size();

        for(int i=0;i<n;i++){

            int second=intervals[i][1];
            int j=i;
            while(j<n-1 && second>=intervals[j+1][0]){
                 second=max(second,intervals[j+1][1]);
                j++;
               
            }

            result.push_back({intervals[i][0],second});
            i=j;
        }
        return result;
    }
};