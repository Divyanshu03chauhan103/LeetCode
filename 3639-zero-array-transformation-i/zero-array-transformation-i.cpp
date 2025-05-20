class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        vector<int>diff(n,0);

        for(auto q:queries){
            int start = q[0];
            int end = q[1]+1;

            diff[start]+=1;

            if(end<n){
                diff[end]-=1;
            }
        }

        vector<int>operations(n,0);
        int cum_sum=0;

        for(int i=0;i<n;i++){
            cum_sum+=diff[i];

            operations[i]=cum_sum;
        }

        for(int i=0;i<n;i++){
            if(operations[i]<nums[i]) return false;
        }

        return true;
    }
};