/*
created by sanyam singhal
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define w(t) \
  int t;     \
  cin >> t while (t--)
#define triplet pair<int, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define fastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define loop(i, k, n) for (ll i = k; i < n; i += 1)
#define loop2(i, k, n) for (ll i = k; i >= n; i--)

const ll inf = 1e18;

void take_fileIO()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  return;
}

void addEdge(vector<vector<vector<int>>> &adj, int u, int v, int wt)
{
  vector<int> a = {v, wt};
  adj[u].push_back(a);
  vector<int> b = {u, wt};
  adj[v].push_back(b);
  return;
}

void solve_by_prims()
{
  //taking input
  int v, e;
  cin >> v >> e;

  vector<vector<vector<int>>> adj(v + 1);
  for (int i = 0; i < e; i++)
  {
    int wt, u, v;
    cin >> u >> v >> wt;
    addEdge(adj, u, v, wt);
  }

  //initializing variables
  vector<int> parent(v + 1);
  vector<bool> visited(v + 1, false);
  vector<int> weight(v + 1);

  loop(i, 0, v + 1)
  {
    weight[i] = INT_MAX;
  }
  //initialization done

  weight[0] = 0;
  parent[0] = -1;
  set<pair<int, int>> s;
  s.insert(mp(weight[0], 0));

  while (!s.empty())
  {
    pi p = *(s.begin());
    s.erase(s.begin());

    int node = p.second;
    visited[node] = true;
    for (vector<int> list : adj[node])
    {
      int neigh = list[0];
      int wt = list[1];

      if (!visited[neigh] && wt < weight[neigh])
      {
        cout << node << "--->" << neigh << " weight=" << wt << endl;
        //update it in the set also
        // 1.delete
        if (s.find(mp(weight[neigh], neigh)) != s.end())
          s.erase(s.find(mp(weight[neigh], neigh)));

        parent[neigh] = node;
        weight[neigh] = wt;

        // 2. insert the updated one into the set
        s.insert(mp(weight[neigh], neigh));
      }
    }
  }

  int sum = 0;
  cout << "---\n";
  for (int i = 1; i < v; i++)
  {
    cout << parent[i] << "--->" << i << "\t weight = " << weight[i] << endl;
    sum += weight[i];
  }
  cout << sum << endl;
  return;
}

int main()
{

  fastIO;
  take_fileIO();

  solve_by_prims();

  return 0;
}