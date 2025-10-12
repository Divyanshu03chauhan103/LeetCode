class Solution {
public:
    int longestBalanced(string s) {
        
        int result=1;
        int n=s.size();

        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(check(mp)){
                    result = max(result,j-i+1);    
                }
            }
        }
        return result;
    }
    bool check(unordered_map<char,int>&mp){
        int first_key = mp.begin()->second;
        for(auto [key,val]:mp){
            if(val!=first_key) return false;
        }
        return true;
    }
};