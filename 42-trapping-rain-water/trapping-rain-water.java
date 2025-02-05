class Solution {
    public int trap(int[] height) {
        int n=height.length;
        int left_boundary[] = new int[n];

        int right_boundary[]=new int[n];

        
        for(int i=0;i<n;i++){

            if(i==0){
                left_boundary[i]=height[i];
            }
            else if(left_boundary[i-1]>height[i])
                left_boundary[i]=left_boundary[i-1];
            else
                left_boundary[i]=height[i];
            
            if(i==0)
                right_boundary[n-i-1]=height[n-i-1];
            else if(right_boundary[n-i]>height[n-i-1])
                right_boundary[n-i-1]=right_boundary[n-i];
            else 
                right_boundary[n-i-1]=height[n-i-1];

        }
        int tw=0;
        for(int i=0;i<n;i++){

            tw+= Math.min(left_boundary[i],right_boundary[i])-height[i];
        }
        return tw;
    }
}