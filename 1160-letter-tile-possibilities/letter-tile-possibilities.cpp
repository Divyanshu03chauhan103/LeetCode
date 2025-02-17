class Solution {
public:
    void solve(set<string>&result,string tiles,string curr,vector<bool>&used){
        result.insert(curr);

        for(int i=0;i<tiles.size();i++){

            if(used[i]) continue;

            used[i]=true;
            curr.push_back(tiles[i]);

            solve(result,tiles,curr,used);

            used[i]=false;
            curr.pop_back();

        }
        
    }
    int numTilePossibilities(string tiles) {
        set<string>result;
        int n = tiles.size();
        vector<bool>used(n,false);
        solve(result,tiles,"",used);

        return result.size()-1;

    }
};