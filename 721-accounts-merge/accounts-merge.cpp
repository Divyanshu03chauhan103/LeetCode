class Disjoint{

    public:
        vector<int>parent,size;
        Disjoint(int n){
            parent.resize(n+1);
            size.resize(n+1,0);

            for(int i=0;i<n+1;i++){
                parent[i]=i;
            }
        }

        int find(int node){
            if(parent[node]==node){
                return node;
            }

            return parent[node]=find(parent[node]);
        }

        void unionbysize(int v,int u){

            int ult_v=find(v);
            int ult_u=find(u);

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n=accounts.size();
        Disjoint ds(n);

        unordered_map<string,int>mp;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(!mp.count(accounts[i][j]))
                    mp[accounts[i][j]]=i;
                else{
                    ds.unionbysize(i,mp[accounts[i][j]]);
                }
            }
        }

        vector<string>mails[n];
        
        for(auto i:mp){
            int node=ds.find(i.second);
            mails[node].push_back(i.first);
        }

        vector<vector<string>>result;

        for(int i=0;i<n;i++){

            if(mails[i].empty()) continue;

            vector<string>temp;
            temp.push_back(accounts[i][0]);

            sort(mails[i].begin(),mails[i].end());

            for(auto s:mails[i]){
                temp.push_back(s);
            }

            result.push_back(temp);
        }
        return result;
    }
};