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
ll fact[2000001];

void preprocess(){
  fact[0]=1;
  for(int i=1; i<=2000000; i++)
    fact[i] = (fact[i-1] * i)%mod;
  return;
}

ll power(ll x, ll exp){
  if(exp==1)
    return x%mod;
  ll res = power(x, exp/2)%mod;
  return (exp%2==1) ? (res%mod * res%mod * x%mod)%mod : (res%mod * res%mod)%mod;
}

ll inverse(ll num){
  return power(num , mod-2);
}

ll NCR(ll n, ll r){
  return (fact[n]%mod * inverse(fact[r])%mod * inverse(fact[n-r])%mod)%mod;
}

int main(){

  fastIO;
  take_fileIO();
  preprocess();

  // for(int i=1; i<=10; i++)
  //   cout<<fact[i]<<" ";
  // cout<<endl;

  cout<<NCR(5, 2)<<endl;
  cout<<NCR(4, 2)<<endl;
  return 0;
}