class Solution {
    public int mySqrt(int x) {
        
        int low=0;
        int high = x/2;
        int result=0;;
        while(low<=high){

            int mid= low+(high-low)/2;
            if (x<2) return x;
            if( (long)mid * mid == x) return mid;

            if((long)mid * mid > x){
                high=mid-1;
            }else{
                result=mid;
                low=mid+1;
            }
        }
        return result;
    }
}