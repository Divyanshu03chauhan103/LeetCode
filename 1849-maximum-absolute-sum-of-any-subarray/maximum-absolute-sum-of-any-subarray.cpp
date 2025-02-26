class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int result =0;
        int n= nums.size();
        int max_sum= INT_MIN;
        int min_sum = INT_MAX;
        int sum = 0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<0) sum =0;
            max_sum = max(sum,max_sum);
        }
        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>0) sum=0;
            min_sum= min(sum,min_sum);
        }
        return abs(min_sum) > max_sum ? abs(min_sum): max_sum;
    }
};