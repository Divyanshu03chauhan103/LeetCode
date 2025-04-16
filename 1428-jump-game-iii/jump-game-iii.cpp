class Solution {
public:
    bool solve(vector<int>& arr, int i, int n, vector<bool>& visited) {
        if (i < 0 || i >= n || visited[i]) return false;
        if (arr[i] == 0) return true;

        visited[i] = true; 

        return solve(arr, i + arr[i], n, visited) || solve(arr, i - arr[i], n, visited);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);

        return solve(arr, start, n, visited);
    }
};
