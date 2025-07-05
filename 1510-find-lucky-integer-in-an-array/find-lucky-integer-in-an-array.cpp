class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        unordered_map<int,int>mp;
        for(int i:arr){
            mp[i]++;
        }
        int result=-1;
        for(auto [key,val]:mp){
            
            if(key == val){
                result=max(result,val);
            }
        }
        return result;
    }
};