class Solution {
    public String clearDigits(String s) {
         StringBuilder sb=new StringBuilder();

            for(char ch : s.toCharArray()){

                if(Character.isLetter(ch))
                    sb.append(ch);
                else
                    sb.deleteCharAt(sb.length()-1);
            }
            
            return sb.toString();
    }
}