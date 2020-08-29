/*
  User:- sanyam
*/

#include<bits/stdc++.h>
using namespace std;

#define ip(x) ll x; cin>>x;
#define op(x) cout<<x;
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
const int N =100001;

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}


/* ---------------------Code--------------------  */
void print(multiset<int> ms) {
  for(int x :ms) {
    cout<<x<< " ";
  }
  cout<<endl;
}

int resolve(vector<int> &path, vector<int>&val, int n) {
  multiset<int>ms;
  
  for(int i=0; i<path.size(); i++) {
    ms.insert(val[path[i]]);
  }

  // print(ms);

  int ans=INT_MAX;
  int prev=-1;
  for(int x : ms) {
    if(prev==-1) {
      prev = x; 
      continue;
    }
    else {
      if(x-prev==0) return 0;
      ans = min(ans, x-prev);
      prev=x;
    }
  }
  return ans;
}

bool dfs(vector<int> adj[], int src, int target, int par, vector<int> &path) {
  if(src==target) {
    return true;
  }

  else {

    for(int child : adj[src]) {
      if(child!=par) {
        path.push_back(child);
        if(dfs(adj, child, target, src, path))
          return true;
        path.pop_back();
      }
    }
  }
  return false;
}

void printv(vector<int> v) {
  for(int x : v) {
    cout<<x<<" ";
  }
  cout<<endl;
  return;
}

void dfs_for_depth(vector<int>adj[], int node, int par, vector<int> &depth, vector<int> &parent, int d=0) {
  depth[node] = d;
  parent[node] = par;
  for(int child : adj[node]) {
    if(par!=child) {
      dfs_for_depth(adj, child, node, depth, parent,  d+1);
    }
  }
  return;
}

void solve() {
  int n,q; cin>>n>>q;
  vector<int> val(n+1, 0);
  for(int i=1; i<=n; i++) {
    cin>>val[i];
  }

  vector<int>adj[n+1];
  for(int i=1; i<n; i++) {
    int u,v;  cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int>depth(n+1, 0);
  vector<int>parent(n+1, 0);
  dfs_for_depth(adj, 1, -1, depth, parent);

  while(q--) {
    int qu, qv; cin>>qu>>qv;
    vector<int>path;
    // path.push_back(qu);
    // dfs(adj, qu, qv, -1, path);
    int flag=0;
    int a = qu, b=qv;
    while(a!=b) {
      if(depth[a] > depth[b]) {
        path.push_back(a);
        a = parent[a];
      }
      else if(depth[b] > depth[a]) {
        path.push_back(b);
        b = parent[b];
      }
      else {
        path.push_back(a);  path.push_back(b);
        a = parent[a];
        b = parent[b];
      }
      if(path.size()>100) {
        flag=1;
        break;
      }
    }

    path.push_back(a);

    // for(int x :path) {
    //   cout<<x<<" ";
    // }
    // cout<<endl;
    if(flag==1) {
      cout<<"0\n";
    }
    else{
      // printv(path);
      ll find_ans = resolve(path, val, n);
      cout<<find_ans<<endl;
    }
  }


}

int main(){

  fastIO;
  take_fileIO();
  int t;  cin>>t;
  while(t--) {
    solve();
  }
  return 0;
}