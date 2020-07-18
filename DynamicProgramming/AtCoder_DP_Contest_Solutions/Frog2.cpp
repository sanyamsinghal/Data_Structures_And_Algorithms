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
    ll n,k; cin>>n>>k;
    vll heights(n);

    loop(i, 0, n)
      cin>>heights[i];

    vll dp(n+1, 0);

    loop(i, 1, n){
      dp[i] = LLONG_MAX;
      for(ll j=i-1; j>=0 && j>=(i-k); j--){
        ll only_option = dp[j] + abs(heights[j]-heights[i]);  //jump from some j to i

        dp[i] = min(dp[i], only_option);
      }
    }
    
    cout<<dp[n-1]<<endl;
    return;
  }

  int main(){

    fastIO;
    take_fileIO();  
    
    solve();

    return 0;
  }