#include <bits/stdc++.h>
using namespace std;

// Double Hashing Constants
const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const long long BASE1 = 31;
const long long BASE2 = 37;

void solve() {
    string pattern = "pcm";
    string text = "pcmhacepcmhacker";

    int T = text.length();
    int S = pattern.length();

    // Precompute powers
    vector<long long> pow1(T + 1, 1), pow2(T + 1, 1);

    for (int i = 1; i <= T; i++) {
        pow1[i] = (pow1[i - 1] * BASE1) % MOD1;
        pow2[i] = (pow2[i - 1] * BASE2) % MOD2;
    }

    // Prefix hashes for the text
    vector<long long> hash1(T + 1, 0), hash2(T + 1, 0);

    for (int i = 1; i <= T; i++) {
        hash1[i] = (hash1[i - 1] * BASE1 + (text[i - 1] - 'a' + 1)) % MOD1;
        hash2[i] = (hash2[i - 1] * BASE2 + (text[i - 1] - 'a' + 1)) % MOD2;
    }

    // Compute hash of the pattern
    long long patternHash1 = 0, patternHash2 = 0;

    for (char c : pattern) {
        patternHash1 = (patternHash1 * BASE1 + (c - 'a' + 1)) % MOD1;
        patternHash2 = (patternHash2 * BASE2 + (c - 'a' + 1)) % MOD2;
    }

    // Count matches
    int countMatches = 0;

    for (int i = 0; i + S <= T; i++) {
        long long curHash1 =
            (hash1[i + S] - (hash1[i] * pow1[S]) % MOD1 + MOD1) % MOD1;

        long long curHash2 =
            (hash2[i + S] - (hash2[i] * pow2[S]) % MOD2 + MOD2) % MOD2;

        if (curHash1 == patternHash1 && curHash2 == patternHash2) {
            countMatches++;
        }
    }

    cout << countMatches << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
