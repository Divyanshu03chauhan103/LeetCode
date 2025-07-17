class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, map<pair<int,int>, int>& dp) {
        if (i > j) return 0;

        if (dp.find({i, j}) != dp.end()) return dp[{i, j}];

        int mini = INT_MAX;
        for (int ind = i; ind <= j; ind++) {
            int cost = cuts[j+1] - cuts[i-1]
                       + solve(i, ind - 1, cuts, dp)
                       + solve(ind + 1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[{i, j}] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        map<pair<int, int>, int> dp;
        return solve(1, c, cuts, dp);
    }
};
