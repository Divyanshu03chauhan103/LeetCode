class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int>freq(26,0);
        int result=0;
        for(auto i:tasks){
            
            freq[i-'A']++;
        }

        priority_queue<int>pq;

        for(auto i:freq){
            if(i>0)
            pq.push(i);
        }
        
        while(!pq.empty()){

            vector<int>temp;

            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                int element= pq.top();
                pq.pop();
                element--;
                temp.push_back(element);
                }
            }

            for(auto i:temp){
                if(i>0){
                    pq.push(i);
                }
            }

            if(pq.empty()){
                result+=temp.size();
            }
            else{
                result+=n+1;
            }
        }
        return result;
    }
};