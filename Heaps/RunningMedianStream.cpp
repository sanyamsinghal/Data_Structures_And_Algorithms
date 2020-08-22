/*
  In this question we need to cater the online queries for median because the numbers are comming one by one.
  1) We can do insertion sort, i.e. put every incoming element to its correct place but it will take O(N^2)
  2) We can have a balanced tree in which we can search.
   Better to have 2 heaps in which one has all the smaller elements and one has all the larger element then median.
   So one left one is max heap and right one is min heap. So answer is either their tops or average of their tops.
     
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
const int N =100001;

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}


/* ---------------------Code--------------------  */

void solve() {
  int n; cin>>n;
  vector<int>arr(n);

  for(int i=0; i<n; i++)
    cin>>arr[i];
  
  priority_queue<int>left_maxh;
  priority_queue<int, vector<int>, greater<int>>right_minh;

  left_maxh.push(arr[0]);
  double median = arr[0];
  for(int i=1; i<n; i++) {
    double element = arr[i];
    cout<<median<<" ";

    if(left_maxh.size() > right_minh.size()) {
      if(arr[i] > median) {
        right_minh.push(arr[i]);
      }
      else {
        left_maxh.push(arr[i]);
        right_minh.push(left_maxh.top()); left_maxh.pop();
      }
      median = (left_maxh.top() + right_minh.top())/2;
    }
    else if(left_maxh.size() < right_minh.size()) {
      if(arr[i]<median) {
          left_maxh.push(arr[i]);
      }
      else {
        right_minh.push(arr[i]);
        left_maxh.push(right_minh.top()); right_minh.pop();
      }
      median = (left_maxh.top() + right_minh.top())/2;
    }
    else {
      if(arr[i]>median){
        right_minh.push(arr[i]);
        median = right_minh.top();  
      }
      else{
        left_maxh.push(arr[i]);
        median = left_maxh.top();
      }
    }
 
  }
  cout<<median<<endl;

}

int main(){
  fastIO;
  // take_fileIO();
  int t=1
  while(t--) {
    solve();
  }
  return 0;
}