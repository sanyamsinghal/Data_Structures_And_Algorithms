  /*
  created by Sanyam Singhal
  /*/

  #include<bits/stdc++.h>
  using namespace std;

  #define pb push_back
  #define mp make_pair
  #define ll long long int
  #define mod 1000000007
  #define w(t) int t;	cin>>t while(t--)
  #define vi vector<int>
  #define vll vector<ll>
  #define pi pair<int,int>
  #define pll pair<ll,ll>
  #define fastIO ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
  #define loop(i, k, n) for(ll i=k; i<n; i+=1)
  #define loop2(i, k, n) for(ll i=k; i>=n; i--)

  void dfs(vector<vector<int>> &adj, int src, bool vis[], vector<int> &parent, vector<int> &childs, int par){
    vis[src]=true;
    parent[src]=par;
    
    int c=0;
    for(int neigh : adj[src]){
      if(vis[neigh]==false){
        dfs(adj, neigh, vis, parent, childs, src);
        c++;
      }
    }
    
    childs[src]=c;
    return;
  }
  
void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

  void solve(){
    int n,e;  cin>>n>>e;
    vector<vector<int>>adj(n+1);

    for(int i=1; i<=e; i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    bool vis[n+1]={false};
    vector<int>parent(n+1, 0);
    vector<int>childs(n+1, 0);

    int ans=0;
    for(int i=1; i<=n; i++){
      if(vis[i]==false){
        dfs(adj, i, vis, parent, childs, -1);
      }
    }

    for(int i=1; i<=n; i++){
      if(parent[i]!=-1 && childs[i] > childs[parent[i]])
        ans++;
    }

    cout<<ans<<endl;
    return;
  }

  int main(){

    fastIO;
    take_fileIO();
    solve();
    return 0;
  }