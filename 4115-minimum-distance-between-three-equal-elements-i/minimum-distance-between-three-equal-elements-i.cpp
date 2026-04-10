class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int result = INT_MAX;

        for (auto& [key, v] : mp) {
            if (v.size() >= 3) {
                for (int i = 0; i <= v.size() - 3; i++) {
                    int dist = 2 * (v[i + 2] - v[i]);
                    result = min(result, dist);
                }
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};