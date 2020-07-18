/*
    User:- sanyam
*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>

PBDS;

const ll inf = 1e18;
const int N =100001;

void take_fileIO(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    return;
}


/* ---------------------Code--------------------  */

int main(){

    fastIO;
    take_fileIO();

    PBDS pbds;
    pbds.insert(5);
    pbds.insert(15);
    pbds.insert(50);
    pbds.insert(2);
    pbds.insert(1);
    pbds.insert(0);
    
    for(int i=0; i<pbds.size(); i++) {
        cout<<*pbds.find_by_order(i)<<endl;
    }

    cout<<pbds.order_of_key(12);

    return 0;
}