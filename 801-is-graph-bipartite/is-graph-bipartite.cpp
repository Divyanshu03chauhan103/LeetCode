class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>sets(n,0);

        queue<int>q;
        
        for(int i=0;i<n;i++){
        if(sets[i]!=0) continue;
                q.push(i);
                sets[i]=1;
               
                while(!q.empty()){

                    int node=q.front();
                    for(auto i:graph[node]){

                        if(sets[i]!=0 && sets[node]==sets[i]){
                            return false;
                        }else if(sets[i]==0){

                            sets[i]= sets[node]==1 ? -1:1; 
                            q.push(i);
                        }
                    }
               
                    q.pop();
                }
        }
       
        return true;
    }
};