class Solution {
public:
    
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mp1;
        
        for(string i:words){
            mp1[i]++;
        }

        int j=0;
        int i=0;
        int n1=s.size();
        int n3=words[0].size();
        int n2=words.size()*n3;
        
        vector<int>result;
        while(j<n1){
          
          if(j-i+1==n2){
                
                unordered_map<string,int>mp2;
                // cout<<i<<" "<<j<<endl;
                for(int k=i;k<=j;k+=n3){
                    
                    mp2[s.substr(k,n3)]++;
                }
                // for(auto [key,val]:mp2){
                //     cout<<key<<"->"<<val<<",";
                // }
                if(mp1==mp2) result.push_back(i);
                i++;
                // cout<<"new";
          }
          j++;
        }
        return result;

    }
};