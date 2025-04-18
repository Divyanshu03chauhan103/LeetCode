class Solution {
public:
    string RLE(string s){
        string result="";
        int count=1;
        char c=s[0];
        
        for(int i=1;i<s.length();i++){
            if(s[i]==c) count++;
            else{
                result+=to_string(count);
                result.push_back(c);
                c=s[i];
                count=1;
            }
        }

        result += to_string(count);
        result.push_back(c);

        return result;
    }
    string solve(int n){
        if(n==1) return "1";
        
        string s = solve(n-1);
        
        return RLE(s);
    }
    string countAndSay(int n) {
        return solve(n);
    }
};

