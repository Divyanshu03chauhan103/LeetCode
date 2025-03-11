class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int result=0;
        int n=s.size();
        int a=0;
        int b=0;
        int c=0;
        int i=0;
        for(int r=0;r<n;r++){
            
            if(s[r]=='a')   a++;
            else if(s[r]=='b')   b++;
            else   c++;
            while(a!=0 && b!=0 && c!=0){
                result+=s.length()-r;
                
                if(s[i]=='a')   a--;
                else if(s[i]=='b')   b--;
                else   c--;

                i++;  
            }
           
        }

        return result;
    }
};