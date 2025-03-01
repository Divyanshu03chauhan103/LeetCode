class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        vector<pair<int,int>>feq;
        
        for(int i:nums){
            mp[i]++;
        }
        for(auto [key,val]:mp){
            feq.push_back({key,val});
        }
        
        sort(feq.begin(),feq.end(),[&](pair<int,int>a,pair<int,int>b){
            return a.second>b.second;
        });

         vector<int>result;
        for(auto i:feq){
            result.push_back(i.first);
            k--;
            if(k==0) break;
        }
       
        return result;
    }
};