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

void solve(){
  ll n; cin>>n;
  ll arr[n][3];

  loop(i, 0, n){
    loop(j, 0, 3){
      cin>>arr[i][j];
    }
  }

  ll dp[n][3];
  memset(dp, 0, sizeof(dp));
  //initializing the dp for first row.
  dp[0][0] = arr[0][0], dp[0][1] = arr[0][1], dp[0][2] = arr[0][2];

  loop(i, 1, n){
    loop(j, 0, 3){
      loop(k, 0, 3){
        if(j!=k){ //this is just for not taking cases like when we select same activity on day i and i-1.
          dp[i][j] = max(dp[i][j], dp[i-1][k] +  arr[i][j]);
        }
      }
    }
  }

  ll final_ans = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
  cout<<final_ans<<endl;
  return;
}

int main(){

  fastIO;
  take_fileIO();

  solve();

  return 0;
}

/*
  Here we can also optimize the space by just taking the n=2 for dp array
  because here we only need to consider the previous row's values only.
*/