/*
created by sanyam singhal
*/
#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
#include<set>
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

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

void toposort(vector<set<char>> &adj, int i, list<char> &ans, bool vis[]){
  vis[i]=true;

  for(char c : adj[i]){
    if(!vis[c -'a']){
      toposort(adj, c-'a', ans, vis);
    }
  }

  ans.push_front((char)(i+'a'));
  return;
}

pair<char, char> matchDiff(string s1, string s2){
  int len = min(s1.size(), s2.size());
  int i=0;
  while(i<len){
    if(s1[i]!=s2[i])
      return mp(s1[i], s2[i]);
    i++;
  }
  return mp('0', '0');
}

void solve(){
  int n, k;
  cin>>n>>k;

  vector<string>words(n);
  loop(i, 0, n){
    cin>>words[i];
    // cout<<words[i]<<" ";
  }

  vector<set<char>>adj(k);
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      string word1 = words[i], word2 = words[j];
      pair<char, char> diff = matchDiff(word1, word2);

      if(diff != mp('0', '0')){
        adj[diff.first - 'a'].insert(diff.second);
      }

    }
  }

  // for(int i=0; i<k; i++){
  //   cout<<((char)(i + 'a'))<<"------";
  //   for(char c : adj[i]){
  //     cout<<(c)<<", ";
  //   }
  //   cout<<endl;
  // }

  bool vis[27]={false};
  list<char>ans;

  for(int i=0; i<=k-1; i++){
    if(!vis[i]){
      toposort(adj, i, ans, vis);
    }
  }

  string s;
  for(char x : ans){
    s += x;
  }
  cout<<s<<endl;
  return;
}

int main(){

  fastIO;
  take_fileIO();

  int t;  cin>>t;
  while(t--){
    solve();
  }

  return 0;
}