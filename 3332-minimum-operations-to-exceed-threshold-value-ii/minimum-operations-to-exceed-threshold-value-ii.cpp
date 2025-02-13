class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if(nums.size()<2) return -1;
        priority_queue<long,vector<long>,greater<long>>pq(nums.begin(),nums.end());
        
        int count=0;
        while(pq.size()>=2 && pq.top()<k){
            long a=pq.top();
            pq.pop();
            long b = pq.top();
            pq.pop();
            long new_element= a*2+ b;
            pq.push(new_element);
            count++;
        }

        if(pq.top()<k) return -1;

        return count;
    }
};