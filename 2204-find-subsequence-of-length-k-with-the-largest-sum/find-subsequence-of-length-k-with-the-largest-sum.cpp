class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        vector<int>result;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq1;

         while(!pq.empty() && k--){
            int index=pq.top().second;
            int num=pq.top().first;
           pq1.push({index,num});
            pq.pop();
        }
        while(!pq1.empty()){
            
            int num=pq1.top().second;
            result.push_back(num);
            pq1.pop();
        }
        
        return result;
    }
};