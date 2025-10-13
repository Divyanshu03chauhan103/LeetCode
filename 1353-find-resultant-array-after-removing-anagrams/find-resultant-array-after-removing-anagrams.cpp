class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n=s.length();
        int nt=t.length();

       vector<int>mp(26,0);
        if(n!=nt) return false;

        for(int i=0;i<n;i++){

            mp[s[i] - 'a']++;
            mp[t[i] - 'a']--;
        }

        for(int i :mp ){
            if(i!=0) return false;
        }

        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>result;
        result.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            if(isAnagram(words[i],words[i-1])) continue;
            else result.push_back(words[i]);
        }
        return result;
    }
};