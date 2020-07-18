/*
  User:- sanyam
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
#define init_arr(i,val) memset(i, val, sizeof(val))
#define sort_cut(x) (x).begin(), (x).end()

const ll inf = 1e18;

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}


/* ---------------------Code--------------------  */

bool flag=1;

void dfs(vector<int> adj[], vector<bool> &vis, vector<int> &color, int src, int curr_color, int parent) {
  vis[src] = true;
  color[src] = curr_color;

  for(int child : adj[src]) {
    if(!vis[child]){
      dfs(adj, vis, color, child, 3-curr_color, src);
    }
    else if(parent!=child && color[child]==color[src]){
      flag=0;
    }
  }
}

void solve(){
  int v, e;
  cin>>v>>e;

  vector<int>adj[v+1];
  for(int i=0 ;i<e; i++){
    int u, v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int>color(v+1);
  vector<bool>vis(v+1, false);

  dfs(adj, vis, color, 1, 1, -1);

  if(flag==1){
    cout<<"Bipartite\n";
  }
  else{
    cout<<"not bipartite\n";
  }

}

int main(){

  fastIO;
  take_fileIO();
  solve();
  return 0;
}