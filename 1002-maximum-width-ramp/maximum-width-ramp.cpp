class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffix(n,-1);
        
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){

            suffix[i]=max(suffix[i+1],nums[i]);
        }

        int ramp=0;
        int j=0;
        for(int i=0;i<n;i++){

            while(j<n && nums[i]<=suffix[j]){
                j++;
            }
            j--;
            ramp=max(j-i,ramp);
            
        }

        return ramp;
    }
};