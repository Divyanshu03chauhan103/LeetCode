class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
        Queue<Pair>q=new LinkedList<>();

        HashSet<String>st = new HashSet<>();

        for(String s:wordList){
            st.add(s);
        }
        q.add(new Pair(beginWord,1));

        st.remove(beginWord);

        while(!q.isEmpty()){

            Pair curr=q.poll();

            String word=curr.first;
            
            int steps=curr.second;
            if(word.equals(endWord)) return steps;
            for(int i=0;i<word.length();i++){
                
                for(char j = 'a'; j<='z';j++){
                    char []curr_word=word.toCharArray();

                    curr_word[i]=j;

                    String changed_word=new String(curr_word);

                    if(st.contains(changed_word)){
                        st.remove(changed_word);
                        q.add(new Pair(changed_word,steps+1));
                    }        
                }
            }
        }

        return 0;

    }
}
class Pair{
    String first;
    int second;

    Pair(String a,int b){
        first=a;
        second=b;
    }
}