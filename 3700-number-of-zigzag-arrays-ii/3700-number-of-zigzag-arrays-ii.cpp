class Solution {
public:
    static const int MOD = 1e9 + 7;

    using ll = long long;
    using Matrix = vector<vector<ll>>;

    Matrix multiply(const Matrix &A, const Matrix &B) {
        int sz = A.size();
        Matrix C(sz, vector<ll>(sz, 0));

        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue;
                ll cur = A[i][k];
                for (int j = 0; j < sz; j++) {
                    C[i][j] = (C[i][j] + cur * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int sz = base.size();
        Matrix res(sz, vector<ll>(sz, 0));
        for (int i = 0; i < sz; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(base, res);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;

        vector<ll> init(S, 0);

        for (int a = 0; a < m; a++) {
            for (int b = 0; b < m; b++) {
                if (a == b) continue;
                if (a < b)
                    init[b]++;
                else
                    init[m + b]++;
            }
        }

        Matrix T(S, vector<ll>(S, 0));

        for (int z = 0; z < m; z++) {
            for (int y = 0; y < z; y++) {
                T[z][m + y] = 1;
            }
        }

        for (int z = 0; z < m; z++) {
            for (int y = z + 1; y < m; y++) {
                T[m + z][y] = 1;
            }
        }

        Matrix P = power(T, n - 2);

        vector<ll> ansState(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                ansState[i] = (ansState[i] + P[i][j] * init[j]) % MOD;
            }
        }

        ll ans = 0;
        for (ll x : ansState)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};