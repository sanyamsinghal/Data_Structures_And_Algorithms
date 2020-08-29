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
const int N = 100001;

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
  #endif
  return;
}


/* ---------------------Code--------------------  */
ll n;
ll wt[N];
ll parent[N];
ll maxc[N];
ll minc[N];
ll ans=0;
vector<ll>adj[N];

void dfs(ll node) {
  minc[node] = maxc[node] = wt[node];
  for(ll child : adj[node]) {
    dfs(child);
    maxc[node] = max(maxc[node], maxc[child]);
    minc[node] = min(minc[node], minc[child]);
  }

  ans = max(ans, abs(wt[node]-maxc[node]));
  ans = max(ans, abs(wt[node]-minc[node]));
}

int main(){
  fastIO;
  take_fileIO();  

  cin>>n;
  ll root;
  loop(i, 1, n+1) cin>>wt[i];
  loop(i, 1, n+1) {
    cin>>parent[i];
    if(parent[i]==-1) root = i;
  }

  loop(i, 1, n+1) {
    if(i!=root) {
      adj[parent[i]].push_back(i);
    }
  }

  fill(maxc, maxc+n+1, LLONG_MIN);
  fill(minc, minc+n+1, LLONG_MAX);

  dfs(root);
  cout<<ans<<endl;

  // loop(i, 1, n+1) {
  //   cout<<maxc[i]<<" "<<minc[i]<<endl;
  // }

  return 0;
}