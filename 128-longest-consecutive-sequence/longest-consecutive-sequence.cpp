class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int>st(nums.begin(),nums.end());
        int longest=1;
        for(auto i:st){
            if(st.find(i-1)==st.end()){
                int cnt=1;
                int num=i;
                while(st.find(num+1)!=st.end()){
                    cnt++;
                    num=num+1;
                }
                longest=max(cnt,longest);
            }
        }
        return longest;
    }
};