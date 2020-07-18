/*

Crux :- Multidimensional DP and DP optimizations, Prefix sums

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
ll dp[101][100001];

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

ll rec(vector<ll> &candies, ll k, ll i, ll n){
  if(k==0)
    return 1;
  else if(i==n && k!=0)
    return 0;
  else {
    ll ans=0;

    for(ll id=i; id<n; id++){

    }

  }
}

void solve(){
  ll n, k;  cin>>n>>k;
  vector<ll>candies(n);
  loop(i, 0, n)
    cin>>candies[i];

  cout<<rec(candies, k, 0, n)<<endl;

}

int main(){

  fastIO;
  take_fileIO();
  solve();
  return 0;
}