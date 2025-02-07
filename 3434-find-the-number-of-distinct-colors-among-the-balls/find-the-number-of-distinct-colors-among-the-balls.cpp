class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
      vector<int> result;
        unordered_map<int, int> mp; 
        unordered_map<int, int> freq; 
      
        
        for (vector<int> i : queries) {
            int key = i[0], value = i[1];

           
            if (mp.find(key) != mp.end()) {
                int oldValue = mp[key];
                freq[oldValue]--;
                if (freq[oldValue] == 0) freq.erase(oldValue);
            }

           
            mp[key] = value;
            freq[value]++;
            result.push_back(freq.size());
        }

        return result;
    }
};