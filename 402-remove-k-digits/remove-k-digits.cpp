class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string result="";
        
        stack<char>st;
        int n=num.size();
        if(k==n) return "0";
        for(int i=0;i<n;i++){

            while(!st.empty() && k>0 && st.top()-'0' > num[i] -'0'){
                st.pop();
                k--;
            }

            st.push(num[i]);

        }

        while(!st.empty() && k>0){
             st.pop();
             k--;
            }


        if(st.empty()) return "0";

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        while(!result.empty() && result.back()-'0' == 0) result.pop_back();

        if(result.empty()) return "0";

        reverse(result.begin(),result.end());
        return result;

    }
};