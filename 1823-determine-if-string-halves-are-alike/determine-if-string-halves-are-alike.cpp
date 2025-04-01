class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int count1=0;
        int n=s.length();
        
        for(int i=0;i<n/2;i++){
            if(tolower(s[i])=='a'||tolower(s[i])=='e'||tolower(s[i])=='i'||tolower(s[i])=='o'||tolower(s[i])=='u')
                count1++;
        }

        int count2=0;

        for(int i=n/2;i<n;i++){
             if(tolower(s[i])=='a'||tolower(s[i])=='e'||tolower(s[i])=='i'||tolower(s[i])=='o'||tolower(s[i])=='u')
                count2++;
        }
        return count1==count2;
    }
};