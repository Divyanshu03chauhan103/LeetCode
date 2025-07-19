class Solution {
    public List<String> removeSubfolders(String[] folder) {
        
        int i=0;
        Arrays.sort(folder);

        int n=folder.length;

        while(folder[i]=="/") i++;
        if(i>=n) return new ArrayList<>();

        List<String>result=new ArrayList<>();
        StringBuilder sb = new StringBuilder(folder[i]);
        result.add(folder[i]);

        for(int ind=i+1;ind<n;ind++){
            
            if(folder[ind].length() >= sb.length() && (folder[ind].substring(0,sb.length())).equals(sb.toString())){

                if(folder[ind].charAt(sb.length())=='/') continue;

                sb=new StringBuilder(folder[ind]);

                result.add(folder[ind]);
            }
            else{
                sb=new StringBuilder(folder[ind]);

                result.add(folder[ind]);
            }
        }
        return result;
    }
}