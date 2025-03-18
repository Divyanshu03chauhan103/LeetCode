class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        
        // Iterate over every subarray starting at i
        for (int i = 0; i < n; i++) {
            int bitmask = 0;
            
            // Extend the subarray from i to j
            for (int j = i; j < n; j++) {
                // Check if nums[j] shares any set bits with the current bitmask
                if ((bitmask & nums[j]) == 0) {
                    // Add nums[j] to the bitmask
                    bitmask |= nums[j];
                    // Update maxLength
                    maxLength = max(maxLength, j - i + 1);
                } else {
                    // If the subarray is no longer nice, break the inner loop
                    break;
                }
            }
        }
        
        return maxLength;
    }
};
