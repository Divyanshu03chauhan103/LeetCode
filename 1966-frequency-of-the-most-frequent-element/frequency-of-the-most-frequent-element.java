class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);

        int result=0;
        int n=nums.length;
        int i=0;

        long sum=0;
        for(int j=0;j<n;j++){
            
            sum+=nums[j];

            while((long)(j-i+1)*nums[j]-sum>k){
                sum-=nums[i];
                i++;
            }
            result=Math.max(result,j-i+1);
        }
        return result;
    }
}