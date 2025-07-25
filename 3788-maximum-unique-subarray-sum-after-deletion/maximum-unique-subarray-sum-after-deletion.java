class Solution {
    public int maxSum(int[] nums) {
        
        Set<Integer>posi=new HashSet<>();

        for(int i:nums){
            if(i>0) posi.add(i);
        }
        if(posi.isEmpty()){
            return Arrays.stream(nums).max().getAsInt();
        }

        return posi.stream().mapToInt(Integer::intValue).sum();
    }
}