class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack<pair<int,int>>st;

        int min=nums[0];
        st.push({min,min});
        for(int i=1;i<nums.size();i++){

            while(!st.empty() && st.top().first<=nums[i]){
                st.pop();
            }

            if(!st.empty() && st.top().second<nums[i]) return true;


            if(nums[i]<min) min= nums[i];

            st.push({nums[i],min});
        }

        return false;
    }
};