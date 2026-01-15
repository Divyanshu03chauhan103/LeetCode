class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

     int i=0;
     int j=0;
     int n=nums.size();

     int count=0;

     int result=0;
     while(j<n){
        if(nums[j]==0){
            count++;
            while(i<=j && count>k){
                if(nums[i]==0) count--;
                i++;
            }
        }
        result=max(result,j-i+1);
        j++;
     }   
     return result;
    }
};