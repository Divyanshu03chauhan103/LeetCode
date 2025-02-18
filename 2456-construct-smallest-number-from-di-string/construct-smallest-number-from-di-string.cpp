class Solution {
public:
    string smallestNumber(string pattern) {
        
        stack<char>st;
        string result;
        int counter=1;
        for(int i =0;i<=pattern.size();i++){

            st.push(counter+'0');
            if(i == pattern.size() || pattern[i]=='I')
                while(!st.empty()){
                    result+=st.top();
                    st.pop();
                }

            counter++;
        }
        return result;
    }
};