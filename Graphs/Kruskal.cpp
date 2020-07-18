/*
created by sanyam singhal
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

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

//0 -indexing based DSU
class DSU{
public:
  vector<int>parent;

  DSU(int v){
    parent.resize(v);
    loop(i, 0, v){
      parent[i] = i;
    }
  }

  int get(int x){
    if(parent[x]==x)  return x;
    else return parent[x] = get(parent[x]);
  }

  void unite(int a, int b){
    int spa = get(a);
    int spb = get(b);

    if(spa==spb)  return;
    else{
      parent[spa] = spb;
    }
    return;
  }

};


void solve_by_krushkal(){
  int vertices, edges;
  cin>>vertices>>edges;

  vector<vector<int>>adjacency_list;

  for(int i=0; i<edges; i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    u--;  v--;
    adjacency_list.push_back({wt, u, v});
  }
  
  //sorting the edges in increasing order of weights
  sort(adjacency_list.begin(), adjacency_list.end());

  DSU graph(vertices);
  int mst_sum=0;

  for(int i=0; i<edges; i++){
    int wt = adjacency_list[i][0], x = adjacency_list[i][1], y = adjacency_list[i][2];
    if(graph.get(x) !=graph.get(y)){
      cout<<x<<" "<<y<<" "<<wt<<endl; //edges taken
      graph.unite(x, y);
      mst_sum += wt;

      //here we can also store it as graph adjacency list - vector<vector<int>>graph;
      //graph[u].push_back(v)
      //graph[v].push_back(u)
    }
    else{ //path already exists it means cycle.

    }
  }

  cout<<mst_sum<<endl;
  return;
}

int main(){

  fastIO;
  take_fileIO();

  solve_by_krushkal();

  return 0;
}