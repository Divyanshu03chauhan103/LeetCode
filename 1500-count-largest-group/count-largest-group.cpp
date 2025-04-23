class Solution {
public:
    int countLargestGroup(int n) {
        
        vector<int>mp(37,0);

        for(int i=1;i<=n;i++){

            int j=i;
            long long num=0;
            while(j){
                num+=j%10;

                j=j/10;
            }
            cout<<num<<",";
            mp[num]++;
        }

        int max_num=mp[0];
        for(int i=1;i<37;i++){
            if(max_num<mp[i]){
             
                max_num=mp[i];
            }
        }
        int count=0;

        for(auto i:mp){
            if(i==max_num)
                count++;
        }
        return count;
    }
};