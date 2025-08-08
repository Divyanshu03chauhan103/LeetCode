class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
      vector<int>seen(100001,0);

      for(int i:nums){
        if(seen[i]!=0) return i;
        seen[i]=1;
      }
      return 0;
    }
};