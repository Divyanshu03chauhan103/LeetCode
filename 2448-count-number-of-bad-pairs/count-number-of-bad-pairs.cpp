class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // unordered_map<long long, long long> mp;
        // for(int i = 0; i < nums.size(); i++) {
        //     long long value = nums[i] - i;
        //     mp[value]++;
        // }

        // long long good_pairs = 0;
        // for(auto &[key, val] : mp) {
        //     if(val > 1) {
        //         good_pairs += (val * (val - 1)) / 2;  
        //     }
        // }

        // long long n = nums.size();
        // long long total_pairs = (n * (n - 1)) / 2;

        // return total_pairs - good_pairs;

        unordered_map<int,int>mp;
        long long result=0;

        for(int i=0;i<nums.size();i++){

            int good_pairs=mp[nums[i]-i];

            int total_pairs=i;

            result+=total_pairs-good_pairs;

            mp[nums[i]-i]++;
        }
        return result;
    }
};
