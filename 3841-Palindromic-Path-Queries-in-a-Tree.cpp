#include <vector>
#include <string>
#include <iostream>

using namespace std;

static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
    int timer = 0;
    static const int LOG = 18;

    void dfs(int u, int p, int d, int currMask, const vector<vector<int>>& adj, const string& s,
             vector<vector<int>>& up, vector<int>& depth, vector<int>& tin, vector<int>& tout, vector<int>& initialP) {
        tin[u] = ++timer;
        depth[u] = d;
        up[u][0] = p;
        for (int k = 1; k < LOG; ++k) up[u][k] = up[up[u][k - 1]][k - 1];

        currMask ^= (1 << (s[u] - 'a'));
        initialP[u] = currMask;

        for (int v : adj[u]) {
            if (v != p) dfs(v, u, d + 1, currMask, adj, s, up, depth, tin, tout, initialP);
        }
        tout[u] = timer;
    }

    int getLca(int u, int v, const vector<vector<int>>& up, const vector<int>& depth) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int k = LOG - 1; k >= 0; --k) {
            if (depth[u] - (1 << k) >= depth[v]) u = up[u][k];
        }
        if (u == v) return u;
        for (int k = LOG - 1; k >= 0; --k) {
            if (up[u][k] != up[v][k]) {
                u = up[u][k];
                v = up[v][k];
            }
        }
        return up[u][0];
    }

    void updateBit(vector<int>& bit, int idx, int val, int n) {
        for (; idx <= n; idx += idx & -idx) bit[idx] ^= val;
    }

    int queryBit(const vector<int>& bit, int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res ^= bit[idx];
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<vector<int>> up(n, vector<int>(LOG));
        vector<int> depth(n), tin(n), tout(n), initialP(n);
        timer = 0;
        dfs(0, 0, 0, 0, adj, s, up, depth, tin, tout, initialP);

        vector<int> bit(n + 2, 0);
        vector<bool> ans;
        string curr_s = s;

        for (const string& q : queries) {
            if (q[0] == 'u') {
                int u = 0, i = 7;
                while (q[i] != ' ') {
                    u = u * 10 + (q[i] - '0');
                    i++;
                }
                char c = q.back();
                char oldC = curr_s[u];
                if (oldC != c) {
                    int diff = (1 << (oldC - 'a')) ^ (1 << (c - 'a'));
                    curr_s[u] = c;
                    updateBit(bit, tin[u], diff, n);
                    updateBit(bit, tout[u] + 1, diff, n);
                }
            } else {
                int u = 0, v = 0, i = 6;
                while (q[i] != ' ') {
                    u = u * 10 + (q[i] - '0');
                    i++;
                }
                i++;
                while (i < q.size()) {
                    v = v * 10 + (q[i] - '0');
                    i++;
                }

                int w = getLca(u, v, up, depth);
                int pu = initialP[u] ^ queryBit(bit, tin[u]);
                int pv = initialP[v] ^ queryBit(bit, tin[v]);
                int wMask = 1 << (curr_s[w] - 'a');

                int pathMask = pu ^ pv ^ wMask;
                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};