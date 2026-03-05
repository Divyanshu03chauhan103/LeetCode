class Solution {
public:
    bool IsVowel(char a){
        return a=='a' || a=='e' || a=='i' || a=='o' || a=='u';
    }

    string trimTrailingVowels(string s) {

        int i = s.length() - 1;

        while(i >= 0 && IsVowel(s[i])) {
            i--;
        }

        return s.substr(0, i+1);
    }
};