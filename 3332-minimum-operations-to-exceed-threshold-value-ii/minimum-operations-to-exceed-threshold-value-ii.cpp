class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if(nums.size()<2) return -1;
        priority_queue<long long,vector<long long>,greater<long long>>pq(nums.begin(),nums.end());
        
        int count=0;
        while(pq.size()>=2 && pq.top()<k){
            long long a=pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long new_element= (long long)a*2+ (long long)b;
            pq.push(new_element);
            count++;
        }

        if(pq.top()<k) return -1;

        return count;
    }
};