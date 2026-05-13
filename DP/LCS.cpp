// LCS DP Tabulation
// dp[i][j] = LCS length of first i chars of a and first j chars of b
// Match  -> 1 + dp[i-1][j-1]
// Not Match -> max(dp[i-1][j], dp[i][j-1])
// Time: O(n*m)
// Space: O(n*m)

int lcs(string a, string b) {
    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}
