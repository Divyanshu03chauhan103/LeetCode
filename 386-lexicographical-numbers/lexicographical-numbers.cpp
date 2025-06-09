class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<int>result;

        for(int i=1;i<=9;i++){

            generateOrder(i,n,result);
        }    

       return result;
    }
     void generateOrder(int curr_num,int limit,vector<int>&result){

            if(curr_num>limit) return;

            result.push_back(curr_num);

            for(int i=0;i<=9;i++){
                int next_num = curr_num*10+i;
                if(curr_num<=limit)
                    generateOrder(next_num,limit,result);
                else break;
            }
        }
};