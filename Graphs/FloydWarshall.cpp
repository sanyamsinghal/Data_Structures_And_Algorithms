/*
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

const ll inf = 1e7;

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

ll matrix[101][101];

void floydWarhsall(int v){
  loop(k, 0, v){
    loop(i, 0, v){
      loop(j, 0, v){
        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
      }
    }
  }
  return;
}

void solve(){
  int t;  cin>>t;
  while(t--){
    int v;
    cin>>v;

    loop(i, 0, v){
      loop(j, 0, v){
        string data;
        cin>>data;
        int val;
        if(data=="INF")
          val = inf;
        else
          val = stoi(data);
        matrix[i][j] =val;
      }
    }

    floydWarhsall(v);
    
    loop(i, 0, v){
      loop(j, 0, v){
        if(matrix[i][j]==inf)
          cout<<"INF ";
        else
          cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
    }

  }
}

int main(){

  fastIO;
  take_fileIO();
  solve();

  return 0;
}