class Solution {
    public boolean isIsomorphic(String s, String t) {
        
        Map<Character,Character>mp=new HashMap<>();
        Set<Character>used= new HashSet<>();

        if(s.length()!=t.length()) return false;
        
        for(int i=0;i<s.length();i++){
            if(mp.containsKey(s.charAt(i))){
                if(mp.get(s.charAt(i)) != t.charAt(i)) return false;
            }else{
                if(used.contains(t.charAt(i))) return false;
                used.add(t.charAt(i));
                mp.put(s.charAt(i),t.charAt(i));
            }
        }
        return true;
    }
}