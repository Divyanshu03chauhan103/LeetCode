class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        unordered_map<int,int>mp;
        int result=0;
        for(auto i:answers){
            
            if(!mp.count(i)){
                result+=i+1;
                mp[i]=i+1;
            }else if(mp[i]==1){
                result+=i+1;
                mp[i]=i+1;
            }
            else{
                mp[i]--;
            }
        }

        return result;
    }
};