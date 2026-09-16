class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        vector<long long> dp(k + 1, 0);
        vector<long long> pref(k + 1, 0);

        dp[0] = 1;
        pref[0] = 1;

        for (int i = 1; i < n; i++) {
            vector<long long> ndp(k + 1, 0);
            vector<long long> npref(k + 1, 0);

            ndp[0] = 1;
            npref[0] = (pref[0] + ndp[0]) % MOD;

            for (int j = 1; j <= k; j++) {

                ndp[j] = dp[j];

                ndp[j] = (ndp[j] + pref[j - 1]) % MOD;

                npref[j] = (pref[j] + ndp[j]) % MOD;
            }

            dp.swap(ndp);
            pref.swap(npref);
        }

        return dp[k];
    }
};