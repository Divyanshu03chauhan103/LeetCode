class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        
        int n= original.size();
    
        int lb=bounds[0][0];

        int ub=bounds[0][1];

        for(int i=1;i<n;i++){
            int diff = original[i]-original[i-1];
            lb=lb+diff;
            ub=ub+diff;
            lb=max(lb,bounds[i][0]);
            ub=min(ub,bounds[i][1]);
        }

      

        return ub-lb+1>0? ub-lb+1:0;


    }
};