class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        int mp[26]={0};

        for(char c:sentence){

            int index=c-'a';
            mp[index]++;
        }

        for(auto i:mp){
            if(i==0) return false;
        }
        return true;
    }
};