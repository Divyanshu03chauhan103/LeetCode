class Solution {
public:
    int solve(int n){
        if(n==1) return 0;
        
        int cost = n/2*(n-n/2) + solve(n/2) + solve(n-(n/2));
        return cost;
    }
    int minCost(int n) {
        return solve(n);
    }
};