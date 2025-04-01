class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.length()!=word2.length()) return false;
       unordered_map<int,int>count;
       unordered_map<char,int>letters;
        for(auto i:word1){
            letters[i]++;
        }

        for(auto [key,val]:letters){
            count[val]++;
        }

        unordered_map<char,int>letters2;
        for(auto i:word2){
            if(letters.find(i)==letters.end()) return false;
            letters2[i]++;
        }

        for(auto [key,val]:letters2){
            if(count.find(val)==count.end()) return false;

            count[val]--;
            if(count[val]==0) count.erase(val);
        }
        return true;
    }
};