class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long result = 0;
        unordered_map<long long, long long> mp;
        int i = 0, j = 0, n = nums.size();
        long long pairs = 0;

        while (j < n) {
            pairs += mp[nums[j]];
            mp[nums[j]]++;

            while (pairs >= k) {
                result += n - j;
                pairs -= mp[nums[i]] - 1;
                mp[nums[i]]--;
                i++;
            }

            j++;
        }

        return result;
    }
};
