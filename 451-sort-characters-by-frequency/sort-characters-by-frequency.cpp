class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }

        vector<pair<char,int>>pairs(mp.begin(),mp.end());

        sort(pairs.begin(),pairs.end(),[](pair<char,int>a,pair<char,int>b){
            return a.second>b.second;
        });

        string result="";
        for(int i=0;i<pairs.size();i++){
                char c = pairs[i].first;    
                int k=pairs[i].second;

                result += string(k, c);
        }
        return result;
    }
};