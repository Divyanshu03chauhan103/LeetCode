class Solution {
public:
    char kthCharacter(int k) {
        string s="a";

        while(s.length()<k){
            string temp="";
            for(int i=0;i<s.length();i++){
                temp+=  s[i]=='z'?'a':s[i]+1;
               
            } 
            s=s+temp;
        }
        return s[k-1];
    }
};