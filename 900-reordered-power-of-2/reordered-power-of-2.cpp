class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        if(n==1) return true;

        string num= to_string(n);

        sort(num.begin(),num.end());

        do{
            if(num[0]=='0') continue;

             n = stoi(num);
             if(n==1) return true;
             if(check(n)) return true;
        }
        while(next_permutation(num.begin(), num.end()));

        return false;
    }

    bool check(int n){

        while(n>1){
            if(n%2==0){
                n=n>>1;
            }
            else return false;
        }
        return n==1;
    }
};