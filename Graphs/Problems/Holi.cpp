/*
  Problem - Spoj holiday Accomodation - https://www.spoj.com/problems/HOLI/

  Author: sanyam singhal
*/
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define w(t) int t;	cin>>t while(t--)
#define triplet pair<int,pair<int,int>>
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
#define loop(i, k, n) for(ll i=k; i<n; i+=1)
#define loop2(i, k, n) for(ll i=k; i>=n; i--)

const ll inf = 1e18;
ll ans = 0;

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
  #endif
  return;
}

void addEdge(vector<pair<int,int>> adj[], int u, int v, int wt){
  adj[u].push_back(mp(v,wt));
  adj[v].push_back(mp(u,wt));
  return;
}

int dfs(vector<pair<int,int>> adj[], int select_source, bool vis[], int count[], int n){
  vis[select_source] = true;
  // count[select_source]=1;

  for(pair<int,int> neigh : adj[select_source]) {
    int neigh_vertex = neigh.first;
    int weight = neigh.second;

    if(!vis[neigh_vertex]){
      count[select_source] += dfs(adj, neigh_vertex, vis, count, n);
      int nx = count[neigh_vertex]+1;
      int ny = n - nx;
      // cout<<select_source<<"------"<<neigh_vertex<<" wt = "<<weight<<endl;
      ans += 2*weight* min(nx, ny);
      // cout<<(2*weight* min(nx, ny))<<endl;
      // cout<<ans<<endl;
    }
  }

  return count[select_source]+1;
}

void solve(){
  static int t=1;
  int n; cin>>n;
  vector<pair<int,int>>adj[n+1];

  loop(i, 0, n-1){
    int u,v,wt;
    cin>>u>>v>>wt;
    addEdge(adj, u, v, wt);
  }

  int select_source;
  for(int i=1; i<=n; i++){
    if(adj[i].size()==1) {
      select_source = i;
      break;
    }
  }

  bool vis[n+1]={false};
  int count[n+1]  ={0};
  dfs(adj, select_source, vis, count, n);
  cout<<"Case #"<<t<<": "<<ans<<endl;
  t++;
  return;
}

int main(){

  fastIO;
  take_fileIO();
  int t;  cin>>t;
  while(t--){
    solve();
    ans=0;
  }
  return 0;
}