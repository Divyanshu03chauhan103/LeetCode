class Solution {
public:
    bool isVowel(char a){
        if(a=='A' || a =='E' || a=='I' || a=='O' || a=='U' || a=='a' || a=='e' || a=='i' || a=='o'||a=='u') return true;
        return false;
    }
    bool doesAliceWin(string s) {
        
        int count=0;
        for(char i:s){
            if(isVowel(i)){
                count++;
            }
        }

        if(count==0) return false;
        return count;
    }
};