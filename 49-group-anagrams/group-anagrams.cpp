class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<int>>mp;

        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(i);
        }

        vector<vector<string>>result;
        for(auto [key,val]:mp){
            vector<string>temp;
            for(int i:val){
                temp.push_back(strs[i]);
            }
            result.push_back(temp);
        }
        return result;
    }
};