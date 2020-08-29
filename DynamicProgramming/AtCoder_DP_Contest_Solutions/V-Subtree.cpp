  /*
    dp on trees + optimizations using prefix and suffix arrays.
    
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
  #define all(x) (x).begin(), (x).end()

  const ll inf = 1e18;

  void take_fileIO(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif
    return;
  }


  /* ---------------------Code--------------------  */
  vector<int>tree[100001];
  vector<ll>dp1(100001, -1), dp2(100001, -1);
  bool vis[100001]={false};


  void solve2(ll src, ll m, ll par_ans){
    vis[src] = true;
    dp2[src] = (dp1[src] * (1+par_ans))%m;

    vector<ll>prefix, suffix;

    for(int child : tree[src]) {
      if(!vis[child]){
        suffix.push_back(dp1[child]+1);
        prefix.push_back(dp1[child]+1);
      }
    }

    for(int i=1; i<prefix.size(); i++)
      prefix[i] = (prefix[i] * prefix[i-1])%m;
    
    for(int i=suffix.size()-2; i>=0; i--){
      suffix[i] = (suffix[i+1] * suffix[i])%m;
    }

    int cnt=0;
    for(int child : tree[src]){
      if(!vis[child]){
        ll ways = 1 + par_ans;
        ways = (cnt>0) ? (prefix[cnt-1]*ways)%m : ways;
        ways = (cnt < suffix.size()-1) ? (ways*suffix[cnt+1])%m : ways;
        solve2(child, m, ways);
        cnt++;
      }
    }

    return;
  }

  void solve1(ll src, ll m){
    vis[src] = true;
    dp1[src] = 1;

    for(int child : tree[src]) {
      if(!vis[child]){
        solve1(child, m);
        dp1[src] = (dp1[src] * (1+dp1[child]))%m;
      }
    }
    return;
  } 

  void solve(){
    ll n, m;
    cin>>n>>m;
    
    loop(i, 0, n-1) {
      int x, y; cin>>x>>y;
      tree[x].push_back(y);
      tree[y].push_back(x);
    }

    solve1(1, m);
    memset(vis, false, sizeof vis);
    solve2(1, m, 0);

    for(int i=1; i<=n; i++)
      cout<<dp2[i]<<endl;

    return;
  }

  int main(){

    fastIO;
    take_fileIO();
    solve();
    return 0;
  }