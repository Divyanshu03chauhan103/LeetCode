class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>indices(n,0);
        for(int i=0;i<n;i++) indices[i]=i;

        sort(indices.begin(),indices.end(),[&](int i,int j){
            return nums[i]!=nums[j]?nums[i]<nums[j]:i<j;
        });

        int ramp=0;
        int min_ind=indices[0];
        for(int i=1;i<n;i++){
            min_ind=min(min_ind,indices[i]);
            ramp=max(ramp,indices[i]-min_ind);
        }
        return ramp;
        }
};