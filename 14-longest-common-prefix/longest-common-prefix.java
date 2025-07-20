class Solution {
    public String longestCommonPrefix(String[] strs) {
        
        StringBuilder sb = new StringBuilder(strs[0]);

        int n=strs.length;

        for(int i=1;i<n;i++){
            int j=0;
            
            while( j<sb.length() && j<strs[i].length() && sb.charAt(j)==strs[i].charAt(j) ){
                j++;
            }
            if(j==0) return "";

            sb=new StringBuilder(sb.substring(0,j));
        }
        return sb.toString();
    }
}