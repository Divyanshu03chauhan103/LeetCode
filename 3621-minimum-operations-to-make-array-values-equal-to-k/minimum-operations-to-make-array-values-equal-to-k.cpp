class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }

        int min_ele = mp.begin()->first;

        if(min_ele<k) return -1;

        auto it = mp.rbegin();
        if(it->first==k) return 0;
        ++it;
        int count=0;
        for(;it!=mp.rend();++it){
            int n = it->first;

            count++;
            if(n==k) return count;
        }

        count++;

        return count;
    }
};