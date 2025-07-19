class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        sort(folder.begin(),folder.end());

        int n=folder.size();

        int i=0;

        while(i<n && folder[i]=="/")  i++;

        if(i>=n) return {};

        vector<string>result;

        result.push_back(folder[i]);
        string curr_string=folder[i];
        for(int ind=i+1;ind<n;ind++){ 
            
            if(folder[ind].substr(0,curr_string.length())==curr_string){
                int j = curr_string.length();
                if(folder[ind][j]=='/')
                    continue;
                curr_string=folder[ind];
                result.push_back(folder[ind]);
            }
            else{
                curr_string=folder[ind];
                result.push_back(folder[ind]);
            }
        }
        return result;
    }
};