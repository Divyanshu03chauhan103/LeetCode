class Solution {
    public int maxWidthRamp(int[] nums) {
        int n=nums.length;
        int []suffix = new int[n];
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){

            suffix[i]=Math.max(suffix[i+1],nums[i]);
        }

        int ramp=0;
        int j=0;
        for(int i=0;i<n;i++){

            while(j<n && nums[i]<=suffix[j]){
                j++;
            }
            j--;
            ramp=Math.max(j-i,ramp);
        }
        return ramp;
    }
}