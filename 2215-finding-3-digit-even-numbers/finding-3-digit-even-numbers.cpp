class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        
        int n=digits.size();

        int freq[10] = {0};

         vector<int>result;

        for(const int i:digits){

            freq[i]++;
        }
        for(int i=1;i<10;i++){
            if(freq[i]==0) continue;

            freq[i]--;
            for(int j=0;j<10;j++){
                if(freq[j]==0) continue;
                freq[j]--;

                for(int k=0;k<9;k+=2){
                    
                    if(freq[k]==0) continue;
                    freq[k]--;
                    int num = i*100 + j*10 + k;
                    if(num%2==0)
                        result.push_back(num);
                    freq[k]++;
                }
                freq[j]++;
            }
            freq[i]++;
        }

        return result;
    
    }
};