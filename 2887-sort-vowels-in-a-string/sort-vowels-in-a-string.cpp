class Solution {
public:
    bool isVowel(char a){
        if(a=='A' || a =='E' || a=='I' || a=='O' || a=='U' || a=='a' || a=='e' || a=='i' || a=='o'||a=='u') return true;
        return false;
    }
    string sortVowels(string s) {
        string result=s;

        vector<int>vowel_ind;
        string vowel="";
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                vowel_ind.push_back(i);
                vowel.push_back(s[i]);
            }
        }

        sort(vowel.begin(),vowel.end());
        int j=0;
        for(int i:vowel_ind){
            result[i]=vowel[j];
            j++;
        }
        return result;
    }
};