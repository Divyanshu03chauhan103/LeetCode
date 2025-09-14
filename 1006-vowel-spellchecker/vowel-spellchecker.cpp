class Solution {
public:
    bool isVowel(char a){
        return a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||
               a=='A'||a=='E'||a=='I'||a=='O'||a=='U';
    }

    string removeVowel(string s){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(char &c : s){
            if(isVowel(c)) c = '*';
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> same;
        unordered_map<string,string> capitalization;
        unordered_map<string,string> vowel;

        for (string word : wordlist) {
            same.insert(word);

            string lower = word;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (!capitalization.count(lower)) capitalization[lower] = word;

            string noVowel = removeVowel(word);
            if (!vowel.count(noVowel)) vowel[noVowel] = word;
        }

        vector<string> result;
        for (string word : queries) {
            if (same.find(word) != same.end()) {
                result.push_back(word);
                continue;
            }
            string lowerQuery = word;
            transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

            auto it1 = capitalization.find(lowerQuery);
            if (it1 != capitalization.end()) {
                result.push_back(it1->second);
                continue;
            }

            string noVowelQuery = removeVowel(word);
            auto it2 = vowel.find(noVowelQuery);
            if (it2 != vowel.end()) {
                result.push_back(it2->second);
                continue;
            }

            result.push_back(""); 
        }
        return result;
    }
};
