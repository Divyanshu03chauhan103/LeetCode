class Node{
    Node link[]=new Node[26];
    boolean flag;

    boolean isContains(char c){
        return link[c - 'a'] != null;
        }

    Node get(char c){
        return link[c-'a'];
    }
    void put(char ch,Node node){
        link[ch-'a']=node;
    }
    void setend(){
        flag=true;
    }
}
class Trie {
    Node root;
    public Trie() {
        root = new Node();
    }
    
    public void insert(String word) {
        Node node = root;

        for(int i=0;i<word.length();i++){
            if(node.isContains(word.charAt(i))){
                node=node.get(word.charAt(i));
            }else{
                node.put(word.charAt(i),new Node());
                node=node.get(word.charAt(i));
            }
        }
        node.setend();
    }
    
    public boolean search(String word) {
        Node  node=root;
        for(int i=0;i<word.length();i++){
            if(node.isContains(word.charAt(i))!=true) return false;

            node=node.get(word.charAt(i));
        }
        return node.flag;
    }
    
    public boolean startsWith(String prefix) {
        
        Node node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node.isContains(prefix.charAt(i))) return false;
            node=node.get(prefix.charAt(i));
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */