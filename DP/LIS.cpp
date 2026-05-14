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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ================= RECURSION =================
    int recur(int idx, int prev, vector<int>& nums) {

        if(idx == nums.size()) return 0;

        // not take
        int notTake = recur(idx + 1, prev, nums);

        // take
        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + recur(idx + 1, idx, nums);
        }

        return max(take, notTake);
    }

    // ================= MEMOIZATION =================
    int memo(int idx, int prev, vector<int>& nums,
             vector<vector<int>>& dp) {

        if(idx == nums.size()) return 0;

        if(dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int notTake = memo(idx + 1, prev, nums, dp);

        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + memo(idx + 1, idx, nums, dp);
        }

        return dp[idx][prev + 1] =
               max(take, notTake);
    }

    // ================= TABULATION =================
    int tabulation(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n + 1,
                               vector<int>(n + 1, 0));

        for(int idx = n - 1; idx >= 0; idx--) {

            for(int prev = idx - 1; prev >= -1; prev--) {

                int notTake = dp[idx + 1][prev + 1];

                int take = 0;
                if(prev == -1 || nums[idx] > nums[prev]) {
                    take = 1 + dp[idx + 1][idx + 1];
                }

                dp[idx][prev + 1] =
                    max(take, notTake);
            }
        }

        return dp[0][0];
    }

    // ================= BINARY SEARCH =================
    // store[i] = minimum ending value of LIS of length (i+1)

    int binarySearchLIS(vector<int>& nums) {

        vector<int> store;

        for(auto x : nums) {

            // increasing subsequence extend
            if(store.empty() || store.back() < x) {
                store.push_back(x);
            }

            else {

                // first element >= x
                int idx =
                    lower_bound(store.begin(),
                                store.end(),
                                x) - store.begin();

                store[idx] = x;
            }
        }

        return store.size();
    }

    // ================= DRIVER =================
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // Recursion
        // return recur(0, -1, nums);

        // Memoization
        // vector<vector<int>> dp(n,
        //        vector<int>(n + 1, -1));
        // return memo(0, -1, nums, dp);

        // Tabulation
        // return tabulation(nums);

        // Binary Search
        return binarySearchLIS(nums);
    }
};
