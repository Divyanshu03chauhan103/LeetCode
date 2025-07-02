class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod=1e9+7;
        int result=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>pow(n,0);
        pow[0]=1;
        for(int i=1;i<n;i++){
            pow[i]=(pow[i-1]*2)%mod;
        }

        int i=0;
        int j=n-1;
        while(i<=j){
            
            if(nums[i]+nums[j]<=target){
                result= (result+pow[j-i])%mod;
                i++;
            }
            else j--;
        }
        return result;
    }
};