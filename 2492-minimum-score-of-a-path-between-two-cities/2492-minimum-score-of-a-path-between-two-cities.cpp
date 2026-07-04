class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> vis(n + 1, 0);
        int ans = INT_MAX;

        queue<int> q;
        q.push(1);
        vis[1] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &[v, wt] : adj[u]) {
                ans = min(ans, wt);

                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};