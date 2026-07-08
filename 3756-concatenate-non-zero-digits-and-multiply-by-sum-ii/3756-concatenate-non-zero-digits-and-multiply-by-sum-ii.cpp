class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<int> cnt(n + 1, 0);

        vector<int> digitSum(n + 1, 0);

        vector<long long> prefVal(1, 0);

        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            digitSum[i + 1] = digitSum[i];

            if (s[i] != '0') {
                int d = s[i] - '0';
                cnt[i + 1]++;
                digitSum[i + 1] += d;
                prefVal.push_back((prefVal.back() * 10 + d) % MOD);
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = cnt[l] + 1;
            int R = cnt[r + 1];

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x = prefVal[R];
            long long rem = (prefVal[L - 1] * pow10[len]) % MOD;
            x = (x - rem + MOD) % MOD;

            long long sum = digitSum[r + 1] - digitSum[l];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};