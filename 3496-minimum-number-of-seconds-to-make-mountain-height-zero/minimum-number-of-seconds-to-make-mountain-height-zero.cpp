class Solution {
public:
    typedef long long ll;
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        int maxTime=*max_element(workerTimes.begin(),workerTimes.end());
        ll right= (ll)maxTime*mountainHeight*(mountainHeight+1);

        ll left=1;
        ll result=0;
        while(left<=right){
            ll mid=left+(right-left)/2;

            if(check(mid,mountainHeight,workerTimes)){
                right=mid-1;
                result=mid;
            }else left=mid+1;
        }
        return result;
    }

    bool check(ll mid,int mountainHeight,vector<int>&workerTimes){

        ll height=0;
        for(int i:workerTimes){
            height+= (ll)(sqrt(2*mid/i+0.25)-0.5);
            if(height>=mountainHeight) return true;
        }
        return height>=mountainHeight;
    }

};