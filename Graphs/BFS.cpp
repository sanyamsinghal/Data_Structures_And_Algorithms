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

const ll inf = 1e18;

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

void addEdge(vector<vector<int>> &graph, int u, int v){
  graph[u].push_back(v);
  graph[v].push_back(u);
  return;
}

void solve(){
  int n,e;
  cin>>n>>e;

  vector<vector<int>>graph(n+1, vector<int>(n+1));

  for(int i=0; i<e; i++){
    int u,v;
    cin>>u>>v;
    addEdge(graph, u, v);
  }

  int src;  cin>>src;

  queue<int>q;
  int dist[n+1];
  for(int i=0; i<=n; i++)
    dist[i] = -1;
  
  q.push(src);
  dist[src]=0;

  while(!q.empty()){
    int ele = q.front();  q.pop();

    for(int neigh : graph[ele]){
      if(dist[neigh]==-1){
        q.push(neigh);
        dist[neigh] = dist[ele]+1;
      }
    }

  }

  for(int i=1; i<=n; i++){
    if(src==i)  continue;
    else if(dist[i]==-1)
      cout<<dist[i]<<" ";
    else
      cout<<dist[i]*6<<" ";
  }
  cout<<endl;
  return;
}

int main(){

  fastIO;
  take_fileIO();

  int t;
  cin>>t;
  while(t--){
    solve();
  }

  return 0;
}