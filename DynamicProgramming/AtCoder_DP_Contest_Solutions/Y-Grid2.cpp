  /*

    This is an optimization for based question where the complexity is n*n but here 
    it will be o(obstacles * obstacles) where obstacles are less than grid dimension n.
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
  ll dp[3001];
  ll fact[200005];
  ll invofFact[200005];

  ll power(ll x, ll exp){
    if(exp==0)
      return 1;
    if(exp==1)
      return x%mod;
    ll res = power(x, exp/2)%mod;
    if(exp & 1){
      return (res%mod * res%mod * x%mod)%mod;
    }
    return (res%mod * res%mod)%mod;
  }

  ll inverse(ll num){
    return power(num , mod-2)%mod;
  }

  ll NCR(ll n, ll r){
    return (fact[n]%mod * invofFact[r]%mod * invofFact[n-r]%mod)%mod;
  }

  ll calc_ways(ll i, ll j, ll ei, ll ej){
    ll down = ei-i;
    ll right = ej-j;
    if(down>=0 && right>=0){
      return NCR(down + right, right)%mod;
    }
    return 0;
  }

  bool comp(pll &a, pll &b){
    return (a.first + a.second) < (b.first + b.second);
  }

  void solve_dp_for_obstacles(vector<pll> &obstacles, ll n, ll h, ll w) {
    dp[0] = calc_ways(1, 1, obstacles[0].first, obstacles[0].second)%mod;
    for(int i=1; i<n; i++){
      dp[i] = calc_ways(1, 1, obstacles[i].first, obstacles[i].second)%mod;
      
      for(int j=i-1; j>=0; j--){
        dp[i] = (mod + dp[i]%mod - (dp[j]%mod * calc_ways(obstacles[j].first, obstacles[j].second, obstacles[i].first, obstacles[i].second)%mod)%mod)%mod;
      }
    }
    return;
  }

  void preprocess(){
    fact[0]=1;
    invofFact[0]=1;
    for(ll i=1; i<=200000; i++){
      fact[i] = (fact[i-1]%mod * i%mod)%mod;
      invofFact[i] = inverse(fact[i])%mod;  
    }
    return;
  }

  void solve(){
    preprocess();
    ll h,w,n;
    cin>>h>>w>>n;
    
    vector<pair<ll,ll>>obstacles;
    loop(i, 0, n){
      ll x, y;  cin>>x>>y;
      obstacles.push_back(mp(x, y));
    }
    
    init_arr(dp, -1);
    init_arr(invofFact, -1);

    sort(obstacles.begin(), obstacles.end(), comp);
    solve_dp_for_obstacles(obstacles, n, h, w);

    ll ans = calc_ways(1, 1, h, w)%mod;
    for(int i=0; i<n; i++) {
      ans = (mod + ans%mod - (dp[i]%mod*calc_ways(obstacles[i].first, obstacles[i].second, h, w)%mod)%mod )%mod;
    }

    cout<<ans;
    return; 
  }

  int main(){
    fastIO;
    take_fileIO();
    solve();
    return 0;
  }