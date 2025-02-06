class Solution {
    public int tupleSameProduct(int[] nums) {
        
        Map<Integer,Integer>mp=new HashMap<>();

        int n=nums.length;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(i==j) continue;
                int product = nums[i] * nums[j];
                mp.put(product, mp.getOrDefault(product, 0) + 1);
            }
        }
        int pairs=0;
        for(int value:mp.values()){
            int curr_value=0;
            if(value>=4){
                curr_value=value/2;
                
                pairs+=(curr_value-1)*(curr_value)/2;
            
            }
                
        }

        int result=8*pairs;

        return result;
    }
}