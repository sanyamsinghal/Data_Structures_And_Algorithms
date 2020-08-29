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
int dp[100001][2];

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

int rec(int k, set<int> &s, int p){
  if(k==0)
    return 1-p;
  if(s.size()==1){
    int div =  (k / *(s.begin()));
    return ( div%2 == 1 ) ? p : 1-p;
  }
  else if(dp[k][p]!=-1)
    return dp[k][p];
  else{

    for(int x : s){
      if(x <= k){
        int z;
        if(dp[k-x][1-p]!=-1)
          z = dp[k-x][1-p];
        else{
          dp[k-x][1-p] = rec(k-x, s, 1-p);
          z = dp[k-x][1-p];
        }
        if(z == p)
          return dp[k][p] = p;
      }
    }
    return dp[k][p] = 1-p;
  }
}

void solve(){
  int n,k; cin>>n>>k;
  set<int>s;
  memset(dp, -1, sizeof(dp));

  for(ll i=0; i<n; i++){
    int data;  cin>>data;
    s.insert(data);
  }
  int result = rec(k, s, 1);
  if(result==1)
    cout<<"First\n";
  else
    cout<<"Second\n";
}

int main(){

  fastIO;
  take_fileIO();
  solve();
  return 0;
}