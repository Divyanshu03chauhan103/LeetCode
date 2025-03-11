class Solution {
public:
    long long calculate(string s,int k){

        int i=0;
        long long result=0;
        int a=0,e=0,I=0,u=0,o=0,consonant=0;
        int j=0;
        while(j<s.length()){
            if(s[j]=='a') a++;
            else if(s[j]=='e') e++;
            else if(s[j]=='i') I++;
            else if(s[j]=='o') o++;
            else if(s[j]=='u') u++;
            else consonant++;

            while(a!=0 && e!=0 && I!=0 && o!=0 && u!=0 && consonant>=k){
                result+=s.length()-j;
                if(s[i]=='a') a--;
                else if(s[i]=='e') e--;
                else if(s[i]=='i') I--;
                else if(s[i]=='o') o--;
                else if(s[i]=='u') u--;
                else consonant--;
                i++;
                }
                j++;
        }
        cout<<result;
        return result;
    }
    long long countOfSubstrings(string word, int k) {
        return calculate(word,k)-calculate(word,k+1);
    }
};