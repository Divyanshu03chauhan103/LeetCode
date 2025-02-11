class Solution {
public:
    bool check(stack<char>st,int index,string part){
        stack<char>temp=st;
        int j=index-1;
        while(j>=0){
            if(temp.top()!=part[j])
                return false;
            temp.pop();
            j--;
        }

        return true;
    }
    string removeOccurrences(string s, string part) {
        /*
        Approach 1: o(n^2)
        while(true){

            int index=s.find(part);

            if(index==string::npos)
                break;
            
            s.erase(index,part.length());
        }
        return s;

        */

       /*
       Approach 2:
        stack<char>st;
        int n=s.length();
        int N=part.length();
        int i=0;
        while(i<n){
            st.push(s[i]);
            
            if(st.size()>=part.length() && check(st,N,part))
            {
                int j=0;
                while(!st.empty() && j<N){
                    st.pop();
                    j++;
                }      
            }
            i++;
        }   

        string result="";

        while(!st.empty()){
            result =  st.top()+result;
            st.pop();
        }
            return result;
        */

        string result="";

        int i=0;
        int n=s.length();
        while(i<n){
            result+=s[i];
            if(result.length()>=part.length() && result.substr(result.length()-part.length())==part)
                result.erase(result.length()-part.length());
            i++;
        }
        return result;
    }
};