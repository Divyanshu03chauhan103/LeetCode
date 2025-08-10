class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int i,vector<int>&parent){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i],parent);
    }

    void Union(int x,int y, vector<int>&parent,vector<int>&rank){

        int parent_x=find(x,parent);
        int parent_y=find(y,parent);

        if(parent_x==parent_y) return;

        if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
        }else if(rank[parent_y]>rank[parent_x]){
            parent[parent_x]=parent_y;
        }else{
            parent[parent_x]=parent_y;
            rank[parent_y]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        
        parent.resize(26);
        rank.resize(26,1);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for(string s:equations){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a',parent,rank);
            }
        }
        for(string s:equations){
            if(s[1]=='!'){
                int first_parent=find(s[0]-'a',parent);
                int second_parent=find(s[3]-'a',parent);

                if(first_parent==second_parent) return false;
            }
        }
        return true;
    }
};