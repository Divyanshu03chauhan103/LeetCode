class Solution {
    public int reverse(int x) {
        
        long result=0;
        boolean isNegative=false;
        if(x==Integer.MIN_VALUE) return 0;
        if(x<0){
             isNegative=true;
             x=Math.abs(x);
        }
        
        while(x!=0){
            result = result*10+ x % 10;
            x=x/10;
        }
        if(result<Integer.MIN_VALUE || result>Integer.MAX_VALUE) return 0;
        return isNegative?-(int)result:(int)result;
    }
}