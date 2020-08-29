/*
  This is basically based upon DP where the answer of parent depends upon one of the child node.

  problem link:- https://codeforces.com/problemset/problem/522/A
  
  User:- sanyam
*/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
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

/* ---------------------Code--------------------  */

unordered_map<string,int>mp;
int id=0;
vector<int>adj[1000];
int dp[1000];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int par) {
    dp[node] = 1;
    int mx=0;
    
    for(int child : adj[node]){
        if(child!=par) {
            dfs(child, node);
            mx = max(mx, dp[child]);
        }
    }
    dp[node] += mx;
}

string makeitlower(string s) {
    for(int i=0; i<s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

vector<string> breakStr(string line) {
    vector<string>ans;
    string curr="";

    for(char c : line) {
        if(c==' '){
            curr = makeitlower(curr);
            if(curr!="reposted")
                ans.push_back(curr);
            curr = "";
        }
        else    curr += c;
    }
    if(curr!=""){
        curr = makeitlower(curr);
        if(curr!="reposted")
            ans.push_back(curr);
    }
    // for(string x : ans){
    //     cout<<x<< ", ";
    // }cout<<endl;
    return ans;
}

void solve() {
    int n; cin>>n;
    string temp;
    getline(cin, temp);
    for(int i=0; i<n; i++){
        string line;    
        getline(cin, line);
        
        vector<string> v = breakStr(line);
        int a,b;
        if(mp.find(v[1])==mp.end())
            mp[v[1]] = id++;
        if(mp.find(v[0])==mp.end())
            mp[v[0]] = id++;
        b = mp[v[0]];
        a = mp[v[1]];
        addEdge(a,b);
    }

    dfs(0, -1);
    cout<<dp[0];
    cout<<endl;
}

int main(){

    fastIO;
    solve();

  return 0;
} 