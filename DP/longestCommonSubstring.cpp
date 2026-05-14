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


////////////////////////////////////////////////////////////// MEMOIZATION ////////////////////////////////////////

// Longest Common Substring - Memoization
// dp[i][j] = length of common substring ending at i and j
// Match -> 1 + dp[i-1][j-1]
// Not Match -> 0
// We try all (i,j) because substring can end anywhere
// Time: O(n*m)
// Space: O(n*m)

class Solution {
    int ans = 0;

    int memo(string &a, string &b,
             int i, int j,
             vector<vector<int>> &dp) {

        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(a[i] == b[j]) {

            return dp[i][j] =
                1 + memo(a, b, i - 1, j - 1, dp);
        }

        return dp[i][j] = 0;
    }

public:
    int longestCommonSubstring(string a, string b) {

        int n = a.size();
        int m = b.size();

        vector<vector<int>> dp(n,
                               vector<int>(m, -1));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                ans = max(ans,
                          memo(a, b, i, j, dp));
            }
        }

        return ans;
    }
};
