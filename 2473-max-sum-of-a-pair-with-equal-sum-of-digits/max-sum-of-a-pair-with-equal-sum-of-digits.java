class Solution {
    public int digitSum(int n){

        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    public int maximumSum(int[] nums) {
        int n= nums.length;
        int mp[] =new int[82];
        int result =-1;
        for(int i=0;i<n;i++){
            
            int sum= digitSum(nums[i]);
            if(mp[sum]>0)
                result = Math.max(result,nums[i]+mp[sum]);
            mp[sum]=Math.max(mp[sum],nums[i]);
            
        }      
        return result;
    }
}