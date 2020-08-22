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
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
  #endif
  return;
}


/* ---------------------Code--------------------  */

void build(int *tree, int *arr, int node_id, int s, int e) {
  if(s>e) return;
  if(s==e) {
    tree[node_id] = arr[s];
    return;
  }
  
  int mid = s + (e-s)/2;
  build(tree, arr, 2*node_id, s, mid);
  build(tree, arr, 2*node_id+1, mid+1, e);

  tree[node_id] = tree[node_id*2] ^ tree[2*node_id+1];
  return;
}

int query(int *tree, int node_id, int s, int e, int qs, int qe) {
  if(qs>qe)
    return 0;
  if(s>qe || e<qs){
    return 0;
  }
  else if(s>=qs && e<=qe) {
      return tree[node_id];
  }
  int mid = s + (e-s)/2;
  int left = query(tree, 2*node_id, s, mid, qs, qe);
  int right = query(tree, 2*node_id +1, mid+1, e, qs, qe);
  return left^right;
}

void solve(){
  int n,a,b;  cin>>n>>a>>b;
  int arr[n];
  int tree[4*n+1];
  loop(i, 0, n) cin>>arr[i];

  build(tree, arr, 1, 0, n-1);

  cout<<query(tree, 1, 0, n-1, a-1, b-1)<<endl;

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