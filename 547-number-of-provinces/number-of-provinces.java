class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n= isConnected.length;
        int m=isConnected[0].length;
        ArrayList<ArrayList<Integer>>adj = new ArrayList<>();

        for(int i=0;i<n;i++){
            adj.add(new ArrayList());
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(isConnected[i][j]==1)
                    adj.get(i).add(j);
            }
        }

        boolean vis[] = new boolean[n+1];
        int result=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                result++;
                dfs(i,vis,adj);
            }
        }
        return result;
    }

    public static void dfs(int src,boolean vis[],ArrayList<ArrayList<Integer>>adj){

        vis[src]=true;

        for(int i:adj.get(src)){
            if(!vis[i]){
                dfs(i,vis,adj);
            }
        }
    }
}