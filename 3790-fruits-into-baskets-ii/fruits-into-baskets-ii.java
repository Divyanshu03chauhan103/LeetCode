class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {

        int result=0;
        boolean vis[] = new boolean[1001];

        for(int i=0;i<fruits.length;i++){
            
            for(int j=0;j<fruits.length;j++){
                if(!vis[j] && fruits[i]<=baskets[j]){
                    result++;
                    vis[j]=true;
                    break;
                }
            }
        }
        return fruits.length - result;  
    }
}