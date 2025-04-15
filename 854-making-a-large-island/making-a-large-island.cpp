class Disjoint{

    public:
        vector<int>size,parent;
        Disjoint(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<n+1;i++){
                parent[i]=i;
            }
        }

        int find(int node){
            if(node==parent[node]) return node;

            return parent[node]=find(parent[node]);
        }

        void unionbysize(int v,int u){
            int ult_v=find(v);
            int ult_u=find(u);
            if(ult_v==ult_u) return;
            if(size[ult_v]>size[ult_u]){
                parent[ult_u]=ult_v;
                size[ult_v]+=size[ult_u];
            }else{
                parent[ult_v]=ult_u;
                size[ult_u]+=size[ult_v];
            }
        }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        Disjoint Ds(n*n);
       
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){

                if(grid[r][c]==0) continue;
               
                int Drow[]={+0,+1,+0,-1};
                int Dcol[]={+1,0,-1,+0};

                for(int i=0;i<4;i++){

                    int new_c=c+Dcol[i];
                    int new_r=r+Drow[i];

                    if(new_c>=0 && new_c<n && new_r>=0 && new_r<n && grid[new_r][new_c]){
                        Ds.unionbysize(n*r+c,n*new_r+new_c);
                    }
                }
            }
        }
        int result=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){

                if(grid[r][c]==1) continue;

                int Drow[]={+0,+1,+0,-1};
                int Dcol[]={+1,0,-1,+0};
                unordered_set<int>st;

                for(int i=0;i<4;i++){

                    int new_c=c+Dcol[i];
                    int new_r=r+Drow[i];

                    if(new_c>=0 && new_c<n && new_r>=0 && new_r<n && grid[new_r][new_c]){
                       int comp= Ds.find(n*new_r+new_c);
                        st.insert(comp);
                    }
                }
                int curr_size=0;
                for(auto it:st){
                    curr_size+=Ds.size[it];
                }

                result=max(result,curr_size+1);
            }
        }


        for(int i=0;i<n*n;i++){
            result=max(result,Ds.size[Ds.find(i)]);
        }
        return result;
    }
};