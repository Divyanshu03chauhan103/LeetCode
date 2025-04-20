class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        
        unordered_set<int>visited;
        long long result=0;
        int i=0;
        int n=instructions.size();
        while(i>=0 && i<n){
            cout<<i;
            string s=instructions[i];
            if(visited.find(i)!=visited.end()) break;
            if(s=="add" ){
                visited.insert(i);
                result+=values[i];    
                i++;
            }else{
                visited.insert(i);
                i=i+values[i];
            
            }

        }
        return result;
    }
};