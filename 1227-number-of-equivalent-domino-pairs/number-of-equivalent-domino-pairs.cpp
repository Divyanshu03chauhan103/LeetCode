class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
      
        unordered_map<int, int> mp;

        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
           
            if (a > b) swap(a, b);
            int key = a * 10 + b; 
            mp[key]++;
        }

        int result = 0;
        for (auto& [key, val] : mp) {
           
            result += val * (val - 1) / 2;
        }
        return result;
    }
};
