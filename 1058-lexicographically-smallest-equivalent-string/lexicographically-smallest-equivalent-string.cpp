class Solution {
public:
    char dfs(char i,unordered_map<char,vector<char>>&mp,vector<int>&visited){

        visited[i-'a']=1;
        char min_char=i;

        for(auto ch:mp[i]){
            if(visited[ch-'a']==1) continue;

            min_char=min(min_char,dfs(ch,mp,visited));
        }
        return min_char;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        unordered_map<char,vector<char>>mp;
        int n=s1.size();
        for(int i=0;i<n;i++){

            mp[s1[i]].push_back(s2[i]);
            mp[s2[i]].push_back(s1[i]);
        }

        string ans="";
        vector<char>smallest(26,'.');

        for(auto i:baseStr){
            
            int ind = i-'a';
            if(smallest[ind]!='.'){
                 ans+=smallest[ind];
                 continue;
            }
            vector<int>visited(26,0);
            char c = dfs(i,mp,visited);
            ans+=c;
            smallest[i-'a']=c;
        }

        return ans;
    }
};