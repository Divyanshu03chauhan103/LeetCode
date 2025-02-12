class Solution {
public:
    int digitSum(int n){

        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        
        int n= nums.size();
        unordered_map<int,int>mp;
        int result =-1;
        for(int i=0;i<n;i++){
            
            int sum= digitSum(nums[i]);
            if(mp.find(sum)!=mp.end()){
            
            result = max(result,nums[i]+mp[sum]);
            mp[sum]=max(mp[sum],nums[i]);
            }
            else
                mp[sum] = nums[i];
        }
        return result;
    }
};