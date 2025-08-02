class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        HashSet<String> st = new HashSet<>(wordDict);
        int n = s.length();
        Boolean[][] memo = new Boolean[n][n + 1];
        return solve(n - 1, n, st, s, memo);
    }

    boolean solve(int i, int j, HashSet<String> st, String s, Boolean[][] memo) {
        if (i < 0) return false;
        if (i == 0) return st.contains(s.substring(i, j));

        if (memo[i][j] != null) return memo[i][j];

        if (st.contains(s.substring(i, j)) && solve(i - 1, i, st, s, memo))
            return memo[i][j] = true;

        return memo[i][j] = solve(i - 1, j, st, s, memo);
    }
}
