
--------------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------------

RECURSION:
Exponential

MEMOIZATION:
TC -> O(N^3)
SC -> O(N^2) + O(N) recursion stack

TABULATION:
TC -> O(N^3)
SC -> O(N^2)

// ========================================================
// MEMOIZATION
// ========================================================

int mcmMemo(int i, int j, vector<int> &arr, vector<vector<int>> &dp){

    // Base Case
    if(i == j) return 0;

    // Already Calculated
    if(dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;

    // Partition
    for(int k = i; k < j; k++){

        int cost =
        (arr[i-1] * arr[k] * arr[j]) +
        mcmMemo(i, k, arr, dp) +
        mcmMemo(k+1, j, arr, dp);

        mini = min(mini, cost);
    }

    return dp[i][j] = mini;
}

// ========================================================
// TABULATION
// ========================================================

int mcmTabu(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = n - 1; i >= 1; i--){

        for(int j = i + 1; j < n; j++){

            int mini = INT_MAX;

            for(int k = i; k < j; k++){

                int cost =
                (arr[i-1] * arr[k] * arr[j]) +
                dp[i][k] +
                dp[k+1][j];

                mini = min(mini, cost);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][n-1];
}
int main() {

    vector<int> arr = {10, 20, 30, 40, 50};

    int n = arr.size();

    // ---------------- MEMOIZATION ----------------

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << "Memoization Answer: ";
    cout << mcmMemo(1, n-1, arr, dp) << endl;

    // ---------------- TABULATION ----------------

    cout << "Tabulation Answer: ";
    cout << mcmTabu(arr) << endl;

    return 0;
}
