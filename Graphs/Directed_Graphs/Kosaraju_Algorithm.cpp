/*
  This Algo is for finding Strongly Connected Components in a Directed Graph.
  Actually cycle === strongly connected component in a directed graph.

  In DAG(Directed Acyclic Graph) there are SCC of size=1 only.

  User:- sanyam
*/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long int
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
#define loop(i, k, n) for(ll i=k; i<n; i+=1)
#define loop2(i, k, n) for(ll i=k; i>=n; i--)

const ll inf = 1e18;

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}


/* ---------------------Code--------------------  */
const int N = 1000;

vector<int>graph[N];
vector<int>rev_graph[N];
vector<int>ordering;
bool vis[N];
int color[N+1];

void dfs(int src){ 
  vis[src]=true;
  for(auto child : graph[src]){
    if(!vis[child])
      dfs(child);
  }
  ordering.push_back(src);
}

void dfs_reverse(int src, int col){
  vis[src]=true;
  color[src]=col;
  cout<<src<<" ";
  for(auto child : rev_graph[src]){
    if(!vis[child])
      dfs_reverse(child, col);
  }
}

void solve(){
  int n,m;
  cin>>n>>m;

  while(m--){
    int x, y; cin>>x>>y;
    graph[x].push_back(y);
    rev_graph[y].push_back(x);
  }

  loop(i, 1, n+1){
    if(!vis[i])
      dfs(i);
  } 

  memset(vis, false, sizeof(vis));
  int col=1;
  for(int i=ordering.size()-1; i>=0; i--){
    int node = ordering[i];
    if(!vis[node]){
      dfs_reverse(node, col);
      col++;
      cout<<endl;
    }
  }

  for(int i=1; i<=n; i++){
    cout<<color[i]<<" ";
  }

}

int main(){
  fastIO;
  take_fileIO();
  solve();
  return 0;
}