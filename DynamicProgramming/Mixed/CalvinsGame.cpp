#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);

const ll ninf = -2 * 1e6;

/* ---------------------Code--------------------  */
const int N = 1000001;
ll fw[N+1]={0}, bkw[N+1];

void solve() {
    ll n, k;   cin>>n>>k;
    vector<ll>arr(n+2,0);
    for(ll i=0; i<n; i++)   
        cin>>arr[i];

    k--;    //beacuse we are taking k to be zero index based

    fw[k]=0;
    fw[k+1]=arr[k+1];
    for(ll i=k+2; i<n; i++) {
        fw[i] = max(fw[i-1], fw[i-2])+arr[i];
    }

    bkw[0]=0;
    bkw[1]=arr[0];
    for(ll i=2; i<n; i++) {
        bkw[i] = max(bkw[i-2]+arr[i-2], bkw[i-1]+arr[i-1]);
    }

    ll max_ans=fw[k]+bkw[k];
    for(int i=k; i<n; i++) {
        max_ans = max(max_ans, fw[i]+bkw[i]);
    }
    cout<<max_ans<<endl;
}


int main(){
    fastIO;
    solve();
    return 0;
}