class Solution {
    public int orangesRotting(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int [][]vis= new int[m][n];


        Queue<ArrayList<Integer>>q = new LinkedList<>();

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                if(grid[i][j]==2) {
                    vis[i][j]=1;
                    q.add(new ArrayList(List.of(i,j,0)));
                }
            }
        }
        int result=0;
        int[][] dir = {
                {0, 1},
                {1, 0},
                {0, -1},
                {-1, 0}
            };

        while(!q.isEmpty()){

            ArrayList<Integer> curr = q.poll();

            int i=curr.get(0);
            int j=curr.get(1);
            result=curr.get(2);

            for (int[] d : dir) {
                    int new_i = i + d[0];
                    int new_j = j + d[1];
                    if(new_i>=0 && new_j>=0 && 
                    new_i<m && new_j<n && vis[new_i][new_j] ==0 && 
                    grid[new_i][new_j]==1){
                        q.add(new ArrayList(List.of(new_i,new_j,result+1)));
                        vis[new_i][new_j]=1;
                    }
                }
            }

        for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){

                    if(grid[i][j]==1 && vis[i][j]==0) return -1;
                }
            }
            return result;
    }
}