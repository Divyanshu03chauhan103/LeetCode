class Solution {
    public int numberOfSubstrings(String s) {
        
        int j=0;
        int i=0;
        int a=0,b=0,c=0;
        int result=0;
        for(int r=0;r<s.length();r++){
        if(s.charAt(r)=='a')   a++;
            else if(s.charAt(r)=='b')   b++;
            else   c++;
            while(a!=0 && b!=0 && c!=0){
                result+=s.length()-r;
                
                if(s.charAt(i)=='a')   a--;
                else if(s.charAt(i)=='b')   b--;
                else   c--;

                i++;  
            }
           
        }

        return result;
    }
}