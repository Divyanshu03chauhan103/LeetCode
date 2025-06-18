class Solution {
public:
    int findMin(string s){
       int n=s.length();

       string min_ele="";
       int i=1;
       while( i<n && s[i-1]==s[i]) i++;

       if(i==n) return stoi(string(n,'1'));


       if(s[0]=='1'){
        i=1;
        min_ele+=s[0];
        while((i<n && s[i-1]==s[i])|| (i<n && (s[i]=='0'||s[i]=='1'))){
            min_ele+=s[i];
            i++;
        }
        
        char ele=s[i];
        for(int j=i;j<n;j++){
            if(s[j]==ele) 
                min_ele+='0';
            else min_ele+=s[j];
        }
       }
       else{
        char ele = s[0];
        for(int j=0;j<n;j++){
            if(ele==s[j])
                min_ele+='1';
            else min_ele+=s[j];
        }
       }

       return stoi(min_ele);
    }
    int maxDiff(int num) {
        
        string s = to_string(num);
        int n=s.length();
        
        string max_ele="";
        int j=0;
        while(s[j]=='9'){
            max_ele+=s[j];
            j++;
        }
        char  ele = s[j];
        for(int i=j;i<n;i++){
            if(s[i]==ele)
                max_ele+='9';
            else max_ele+=s[i];
        }
        int max_n=stoi(max_ele);
        
        int min_n=findMin(s);

        return max_n-min_n;
    }
};