class Solution {
    public String makeFancyString(String s) {
        
        StringBuilder sb= new StringBuilder();
        sb.append(s.charAt(0));
        int count=1;
        for(int i=1;i<s.length();i++){
            if(s.charAt(i-1)==s.charAt(i) && count<2){
                count++;
                sb.append(s.charAt(i));
            }
            else if(s.charAt(i-1)!=s.charAt(i)){
                count=1;
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}