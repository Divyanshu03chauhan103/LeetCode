class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int five=0,ten=0,twenty=0;
        bool check =true;
        for(auto i:bills){

            if(i==5){
                five++;
            }
            else if(i==10){
                ten++;
                if(five)
                    five--;
                else check= false;
            }
            else {
                twenty++;
                if(ten&& five)
                    {
                        ten--;
                        five--;
                    }
                    else if( five>=3)
                        five=five-3;
                    else 
                        check =false;
            }
                
        }
        return check;
    }
};