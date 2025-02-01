class Solution {
    public boolean isArraySpecial(int[] nums) {
        
        boolean result=true;

        for(int i=1;i<nums.length;i++){

            if(nums[i-1]%2==0){

                if(nums[i]%2==0){
                    result=false;
                }
            }
            else{

                if(nums[i]%2==1){
                    result=false;
                }
            }
        }
        return result;
    }
}