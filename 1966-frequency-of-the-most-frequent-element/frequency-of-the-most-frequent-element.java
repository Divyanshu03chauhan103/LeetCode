class Solution {
    public int maxFrequency(int[] nums, int k) {
        
        Arrays.sort(nums);

        int n=nums.length;
        int prefix[] = new int[n];
        prefix[0]=nums[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i-1]; 
        }

        int result=1;
        for(int i=n-1;i>=1;i--){

            int freq=binarysearch(i,nums,prefix,k);
            result=Math.max(freq,result);
        }

        return result;
    }

    public int binarysearch(int tar_ind,int[] nums,int[] prefix, int k){
        
        int low= 0;
        int high=tar_ind;
        int freq=0;
        while(low<=high){
            int mid=low+(high-low)/2;

            int count=tar_ind-mid+1;

            int expected_sum=count*nums[tar_ind];

            int curr_sum = prefix[tar_ind]-prefix[mid]+nums[mid];

            int total_changes=expected_sum-curr_sum;
            
            if(total_changes>k){
                low=mid+1;
            }else{
                freq=count;
                high=mid-1;
            }

        }
        return freq;
    }
}