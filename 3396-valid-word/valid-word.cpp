class Solution {
public:
    bool isValid(string word) {
        
        bool vowel =false;
        bool consonant=false;
        bool non_digit=true;
        int count=0;
        
        for(char i:word){
            if(isdigit(i)){
                count++;
            }
            else if(i=='A'||i=='a'||i=='i'||i=='I'||i=='e'||i=='E'||i=='o'||i=='O'||i=='u'||i=='U'){
                 count++;
                 vowel=true;
            }
            else if(isalpha(i)){
                 consonant=true;
                 count++;
            }
            else{
                non_digit=false;
                count++;
            } 
        }
        return non_digit && consonant && vowel && count>=3;
    }
};