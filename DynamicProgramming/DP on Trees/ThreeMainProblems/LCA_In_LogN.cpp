/*
  User:- sanyam
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 5;

vector<int> graph[N + 1];
int up[N + 1][21];
int level[N + 1];

void dfs(int node, int par, int lvl) {
    level[node] = lvl;
    for (int child : graph[node]) {
        if (par == child) continue;
        dfs(child, node, lvl + 1);
    }
}

void binary_lifting(int node, int par) {
    up[node][0] = par;
    for (int i = 1; i <= 20; i++) {
        if (up[node][i - 1] != -1)
            up[node][i] = up[up[node][i - 1]][i - 1];
        else
            up[node][i] = -1;
    }

    for (int child : graph[node]) {
        if (child == par) continue;
        binary_lifting(child, node);
    }
}

int lift_node(int node, int distance_up) {
    for (int i = 20; i >= 0; i--) {
        if (distance_up == 0 || node == -1) break;

        if (distance_up >= (1 << i)) {
            distance_up -= (1 << i);
            node = up[node][i];
        }
    }
    return node;
}

int lca(int u, int v) {
    if (level[u] < level[v]) swap(u, v);

    u = lift_node(u, level[u] - level[v]);

    if (u == v) return u;

    for (int i = 20; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return lift_node(u, 1);
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        graph[u].push_back(i);
        graph[i].push_back(u);
    }

    dfs(1, -1, 0);
    binary_lifting(1, -1);

    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        int ans = lca(u, v);
        cout << ans << endl;
    }

    return 0;
}