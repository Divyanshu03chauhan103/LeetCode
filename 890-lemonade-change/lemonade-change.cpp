class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        if(bills[0]!=5) return false;
        int count5=0,count10=0;
        
        for(auto i : bills){
            if(i==5)
                count5++;
            else if(i==10 && count5){
                count5--;
                count10++;
            }
            else if(i==20 && count10 && count5){
                count10--;
                count5--;
            }
            else if(i==20 && count5>=3){
                count5-=3;
            }
            else  return false;
        }

        return true;
        

    }
};