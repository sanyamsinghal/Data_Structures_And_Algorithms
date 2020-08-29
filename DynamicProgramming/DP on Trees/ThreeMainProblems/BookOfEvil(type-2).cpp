/*
    User:- sanyam
*/

#include<bits/stdc++.h>
using namespace std;

#define ip(x) ll x; cin>>x;
#define op(x) cout<<x;
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
const int N =100002;

void take_fileIO(){
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    return;
}


/* ---------------------Code--------------------  */
vector<ll>graph[N];
ll ninf = -2e5;
bool infected[N] = {false};
ll in_dp[N]={0};
ll out_dp[N] = {0};

void dfs_IN(ll node, ll par) {
    if(infected[node]) in_dp[node]=0;
    else in_dp[node] = ninf;

    for(ll child : graph[node]) {
        if(child!=par) {
            dfs_IN(child, node);
            in_dp[node] = max(in_dp[node], 1+in_dp[child]);
        }
    }
}


void dfs_out(ll node, ll par) {
    ll mx1=ninf, mx2=ninf-1;
    
    for(ll child : graph[node]) {
        if(child!=par) {
            if(in_dp[child] >= mx1) 
                mx2=mx1, mx1=in_dp[child];
            else if(in_dp[child] > mx2)
                mx2 = in_dp[child];
        }
    }

    // cout<<node<<" "<<mx1<<" "<<mx2<<endl;

    for(ll child : graph[node]) {
        if(child!=par) {
            ll use = mx1;
            if(in_dp[child] == mx1)
                use = mx2;

            out_dp[child] = max(1+out_dp[node], 2+use);
            if(infected[child] && out_dp[child]<0)
                out_dp[child]=0;
            
            dfs_out(child, node);
        }
    }

}

void solve() {
    ll n,m,d;
    cin>>n>>m>>d;

    loop(i, 0, m){
        int node; cin>>node;  
        infected[node]=true;
    }

    loop(i, 0, n-1) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(in_dp, -1, sizeof in_dp);
    memset(out_dp, -1, sizeof out_dp);

    dfs_IN(1, -1);
    
    if(infected[1]) out_dp[1] = 0;
    else    out_dp[1] = ninf;

    dfs_out(1, -1);

    for(int i=1; i<=n; i++) {
        if(infected[i]) {
            in_dp[i] = max(in_dp[i], 0LL);
            out_dp[i] = max(out_dp[i], 0LL);
        }
    }
    // cout<<endl;
    
    // for(int i=1; i<=n; i++)
    //     cout<<in_dp[i]<<" ";
    // cout<<endl;

    // for(int i=1; i<=n; i++)
    //     cout<<out_dp[i]<<" ";
    // cout<<endl;



    ll ans=0;
    for(ll i=1; i<=n; i++) {
        if(max(in_dp[i], out_dp[i])<=d && max(in_dp[i], out_dp[i])>=0) {
            ans++;
            // cout<<i<<" "<<endl;
        }
    }
    cout<<ans<<endl;
}

int main(){
    fastIO;
    // take_fileIO();
    solve();
    return 0;
}