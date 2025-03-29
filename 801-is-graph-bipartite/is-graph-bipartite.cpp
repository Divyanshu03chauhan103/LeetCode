class Solution {
public:
    bool dfs(vector<vector<int>>&graph,vector<int>&sets,int node,int color){
        sets[node] = color;
        color = color==1? -1:1;
        for(auto i:graph[node]){

            if(sets[i]!=0 && sets[i]==sets[node]) return false;
            else if(sets[i]!=0) continue;
            else if(dfs(graph,sets,i,color) == false) return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>sets(n,0);
        int color=1;
        for(int i=0;i<n;i++){
            if(sets[i]!=0) continue;

            if(dfs(graph,sets,i,color)==false) return false;
        }

        return true;
    }
};
//bfs approach
// class Solution {
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n=graph.size();
//         vector<int>sets(n,0);

//         queue<int>q;
        
//         for(int i=0;i<n;i++){
//         if(sets[i]!=0) continue;
//                 q.push(i);
//                 sets[i]=1;
               
//                 while(!q.empty()){

//                     int node=q.front();
//                     for(auto i:graph[node]){

//                         if(sets[i]!=0 && sets[node]==sets[i]){
//                             return false;
//                         }else if(sets[i]==0){

//                             sets[i]= sets[node]==1 ? -1:1; 
//                             q.push(i);
//                         }
//                     }
               
//                     q.pop();
//                 }
//         }
       
//         return true;
//     }
// };