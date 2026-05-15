// ================= Longest Increasing Subsequence (LIS) =================
//
// 1. Recursion        -> O(2^N)
// 2. Memoization      -> O(N^2)
// 3. Tabulation       -> O(N^2)
// 4. Binary Search    -> O(N log N)
//
// NOTE:
// prev = -1 means no previous element selected
// dp[idx][prev + 1] because prev can be -1
//
// ================= NEW ADDED =================
//
// PRINTING LIS:
// hash[i] stores previous index of LIS
// lastIndex stores ending index of LIS
// backtrack from lastIndex using hash[]
//
// This approach works for:
// 1. LIS Length
// 2. Printing LIS
//
// TC : O(N^2)
// SC : O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ================= RECURSION =================
    int recur(int idx, int prev, vector<int>& nums) {

        if(idx == nums.size()) return 0;

        int notTake = recur(idx + 1, prev, nums);

        int take = 0;

        if(prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + recur(idx + 1, idx, nums);
        }

        return max(take, notTake);
    }

    // ================= MEMOIZATION =================
    int memo(int idx, int prev,
             vector<int>& nums,
             vector<vector<int>>& dp) {

        if(idx == nums.size()) return 0;

        if(dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int notTake =
            memo(idx + 1, prev, nums, dp);

        int take = 0;

        if(prev == -1 || nums[idx] > nums[prev]) {

            take =
                1 + memo(idx + 1,
                         idx,
                         nums,
                         dp);
        }

        return dp[idx][prev + 1] =
               max(take, notTake);
    }

    // ================= TABULATION =================
    int tabulation(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(n + 1, 0)
        );

        for(int idx = n - 1; idx >= 0; idx--) {

            for(int prev = idx - 1;
                prev >= -1;
                prev--) {

                int notTake =
                    dp[idx + 1][prev + 1];

                int take = 0;

                if(prev == -1 ||
                   nums[idx] > nums[prev]) {

                    take =
                        1 + dp[idx + 1][idx + 1];
                }

                dp[idx][prev + 1] =
                    max(take, notTake);
            }
        }

        return dp[0][0];
    }

    // ================= BINARY SEARCH =================
    // store[i] = minimum ending value
    // of LIS of length (i+1)

    int binarySearchLIS(vector<int>& nums) {

        vector<int> store;

        for(auto x : nums) {

            if(store.empty() ||
               store.back() < x) {

                store.push_back(x);
            }

            else {

                int idx =
                    lower_bound(store.begin(),
                                store.end(),
                                x)
                    - store.begin();

                store[idx] = x;
            }
        }

        return store.size();
    }

    // ================= PRINT LIS =================
    // TC : O(N^2)
    // SC : O(N)

    vector<int> printLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, 1);

        // stores previous index
        vector<int> hash(n);

        int maxi = 1;
        int lastIndex = 0;

        for(int i = 0; i < n; i++) {

            hash[i] = i;

            for(int j = 0; j < i; j++) {

                if(nums[j] < nums[i] &&
                   1 + dp[j] > dp[i]) {

                    dp[i] = 1 + dp[j];

                    // storing previous index
                    hash[i] = j;
                }
            }

            // LIS length
            if(dp[i] > maxi) {

                maxi = dp[i];

                // ending index of LIS
                lastIndex = i;
            }
        }

        vector<int> lis;

        lis.push_back(nums[lastIndex]);

        // backtracking
        while(hash[lastIndex] != lastIndex) {

            lastIndex = hash[lastIndex];

            lis.push_back(nums[lastIndex]);
        }

        reverse(lis.begin(), lis.end());

        return lis;
    }

    // ================= DRIVER =================
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // Recursion
        // return recur(0, -1, nums);

        // Memoization
        // vector<vector<int>> dp(
        //      n, vector<int>(n + 1, -1));
        // return memo(0, -1, nums, dp);

        // Tabulation
        // return tabulation(nums);

        // Binary Search
        return binarySearchLIS(nums);
    }
};
