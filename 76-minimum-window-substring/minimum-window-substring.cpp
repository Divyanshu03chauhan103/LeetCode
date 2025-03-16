class Solution {
public:
    string minWindow(string s, string t) {
        
        int i=0;
        int j=0;
        unordered_map<char,int>mp;

        int minSize=INT_MAX;
        int start=-1;

        for(char i:t){
            mp[i]++;
        }
        int count=mp.size();
        int n=s.size();
        while(j<n){

            if(mp.count(s[j])){
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    count--;
            }

            while(count==0 && i<=j){
                if(minSize>j-i+1){
                    minSize=j-i+1;
                    start=i;
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]>0)
                        count++;
                }
                i++;
                }

                j++;
            }
         
            if(minSize!=INT_MAX){
                return s.substr(start,minSize);
            }

            return "";
        }
};