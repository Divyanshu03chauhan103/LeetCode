class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n=haystack.length();
        int m=needle.length();
        if(m==n) return needle==haystack? 0:-1;
        for(int i=0;i<n;i++){

            if(i+m<=n){
                if(needle==haystack.substr(i,m)) return i;
            }
        }

        return -1;
    }
};