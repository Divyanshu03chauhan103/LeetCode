class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        unordered_set<int>sad_users;

        for(auto frd:friendships){
            int u=frd[0]-1;
            int v=frd[1]-1;

            unordered_set<int>langcheck(languages[u].begin(),languages[u].end());

            bool canTalk=false;
            for(int lang:languages[v]){
                if(langcheck.count(lang)){
                    canTalk=true;
                    break;
                }
            }

            if(!canTalk){
                sad_users.insert(u);
                sad_users.insert(v);
            }
        }

        vector<int>language(n+1,0);
        int max_lang=0;
        for(auto i:sad_users){
            for(int lang:languages[i]){
                language[lang]++;
                max_lang=max(language[lang],max_lang);
            }
        }
        return sad_users.size()-max_lang;
    }
};