class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto i:stones){
            pq.push(i);
        }
        while(pq.size()!=1&&!pq.empty()){
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();

            int smash=y-x;
            if(smash>0) pq.push(smash);
        }
        
        return pq.empty()?0:pq.top();
    }
};