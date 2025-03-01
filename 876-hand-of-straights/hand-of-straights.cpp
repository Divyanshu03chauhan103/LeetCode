class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i:hand){
            pq.push(i);
        }

        while(!pq.empty()){

            vector<int>temp1;
            vector<int>temp2;
            while(!pq.empty() && temp1.size()!=groupSize){
                int ele= pq.top();
                
                pq.pop();
                if(temp1.empty()||ele-temp1.back()==1){
                  
                    temp1.push_back(ele);
                }
                else if(temp1.back()==ele){
                    temp2.push_back(ele);
                }
            }
           
            if(temp1.size()!=groupSize) return false;
            for(int i:temp2){
                pq.push(i);
            }
        }

        return true;
    }
};