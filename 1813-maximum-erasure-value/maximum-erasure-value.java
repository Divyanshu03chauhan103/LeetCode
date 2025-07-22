class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        
        int i=0;
        int n=nums.length;

        int j=0;
        int sum=0;
        int[] freq = new int[10001];
        int max_score=0;
        while(j<n){
            sum+=nums[j];
            freq[nums[j]]++;


            while(i<=j && freq[nums[j]]>1){
               freq[nums[i]]--;
                sum-=nums[i];
                i++;
            }
            max_score=Math.max(sum,max_score);
            j++;
        }
        return max_score;
    }
}