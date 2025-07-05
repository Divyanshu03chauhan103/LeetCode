class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        vector<int>mp(501,0);
        for(int i:arr){
            mp[i]++;
        }
        int result=-1;
        for(int i=1;i<501;i++){
            
            if(i == mp[i]){
                result=max(result,i);
            }
        }
        return result;
    }
};