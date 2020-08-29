/*
  Very good question on DP on Graphs + Matrix Exponentiation
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
#define base(i,val) memset(i, val, sizeof(val))

const ll inf = 1e18;

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}


/* ---------------------From here main coding part starts--------------------  */

vector<vector<ll>> multiply(vector<vector<ll>> a, vector<vector<ll>>b){
  ll n = a.size();
  vector<vector<ll>> res(n, vector<ll>(n, 0));

  loop(i, 0, n){
    loop(j, 0, n){
      loop(k, 0, n){
        res[i][j] = (res[i][j] + a[i][k] * b[k][j])%mod;
      }
    }
  }
  return res;
}

vector<vector<ll>> power(vector<vector<ll>> a, ll exp){
  if(exp==1)
    return a;
  
  vector<vector<ll>>res = power(a, exp/2);
  if(exp&1){
    return multiply(a, multiply(res, res));
  }
  else{
    return multiply(res, res);
  }
}

void solve(){
  ll n, k; 
  cin>>n>>k;
  vector<vector<ll>>adj(n, vector<ll>(n));

  loop(i, 0, n)
    loop(j, 0, n)
      cin>>adj[i][j];

  vector<vector<ll>>Ak = power(adj, k);

  ll ans = 0;
  
  loop(i, 0, n){
    loop(j, 0, n){
      ans = (ans + Ak[i][j])%mod;
    }
  }
  cout<<ans<<endl;
}

int main(){

  fastIO;
  take_fileIO();
  solve();

  return 0;
}