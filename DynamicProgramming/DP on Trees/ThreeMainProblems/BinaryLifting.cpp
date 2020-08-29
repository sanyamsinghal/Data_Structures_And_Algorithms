/*
  User:- sanyam
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 5;

vector<int> graph[N + 1];
int up[N + 1][21];

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

int query_ans(int node, int distance_up) {
    if (node == -1 || distance_up == 0) return node;
    for (int i = 20; i >= 0; i--) {
        if (distance_up >= (1 << i))
            return query_ans(up[node][i], distance_up - (1 << i));
    }
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int u, v;
        cin >> u;
        v = i;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    binary_lifting(1, -1);

    for (int i = 1; i <= q; i++) {
        int u, distance;
        cin >> u >> distance;
        int result = query_ans(u, distance);
        cout << result << endl;
    }

    return 0;
}