class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();

       
        for (int i = n - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                index = i;
                break;
            }
        }

       
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        
        int j = -1;
        for (int i = n - 1; i >= index; i--) {
            if (nums[i] > nums[index - 1]) {
                j = i;
                break; 
            }
        }
  
        swap(nums[index - 1], nums[j]);

        reverse(nums.begin() + index, nums.end());
    }
};
