class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int>odd,even;

        for(int i=0;i<s1.size();i++){
            if(i%2==0) even[s1[i]]++;
            else odd[s1[i]]++;
        }

        for(int i=0;i<s2.size();i++){
            if(i%2==0){
                even[s2[i]]--;
                if(even[s2[i]]==0) even.erase(s2[i]);
            }else{
                odd[s2[i]]--;
                if(odd[s2[i]]==0) odd.erase(s2[i]);
            }
        }
        
        return odd.empty() && even.empty();
    }
};