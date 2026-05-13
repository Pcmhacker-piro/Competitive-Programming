// Longest Common Substring DP Tabulation
// dp[i][j] = length of common substring ending at i-1 and j-1
// Match -> 1 + dp[i-1][j-1]
// Not Match -> 0 (substring must be continuous)
// Time: O(n*m)
// Space: O(n*m)

int longestCommonSubstring(string a, string b) {
    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}
