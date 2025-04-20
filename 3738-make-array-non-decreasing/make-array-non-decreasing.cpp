class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {

        stack<int>st;

        for(int i:nums){

            if(st.empty() || i>=st.top()) st.push(i);
            
        }   
        return st.size();     
    }
};
