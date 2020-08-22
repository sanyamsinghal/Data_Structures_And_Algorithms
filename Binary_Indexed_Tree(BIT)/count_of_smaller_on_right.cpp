    /*
      Problem Statement Link :- https://www.geeksforgeeks.org/count-smaller-elements-on-right-side-and-greater-elements-on-left-side-using-binary-index-tree/?ref=rp
    */


    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    #define mod 100000005

    typedef vector<int> vi;
    typedef vector<ll> vll;
    typedef pair<int, int> pi;
    typedef pair<ll, ll> pll;
    typedef vector<pair<int,int>> vpi;
    typedef vector<pair<ll,ll>> vpll;
    
    bool allow = true;

    int BIT[1000]={0};
    int maxElement;

    void update(int index, int val){
      while (index<=maxElement)
      {
        BIT[index] += 1;
        index = index + (index&(-index));
      }
    }

    int getSum(int index){
      int ans=0;
      while(index>0){
        ans += BIT[index];
        index = index - (index&(-index));
      }
      return ans;
    }


    int main() {
      if(allow){
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      }
      
      // ios_base::sync_with_stdio(false);
      // cin.tie(NULL);
      // cout.tie(NULL);

      int n;  cin>>n;
      int arr[n], left[n], right[n];
      // int maxElement;
      for(int i=0; i<n; i++)  {
        cin>>arr[i];
        maxElement = max(maxElement, arr[i]);
      }
      
      cout<<maxElement<<endl;
      // BIT.resize(maxElement+1, 0);
      memset(BIT, 0, sizeof(BIT));
      for(int i=n-1; i>=0; i--){
        right[i] = getSum(arr[i]-1);
        update(arr[i], 1);
      }

      // BIT.clear();
      // BIT.resize(maxElement+1, 0);
      memset(BIT, 0, sizeof(BIT));
      for(int i=0; i<n; i++){
        left[i] = getSum(maxElement) - getSum(arr[i]);
        update(arr[i], 1);
      }
      
      for(int i=0; i<n; i++){
        cout<<right[i]<<" ";
      }cout<<endl;

      for(int i=0; i<n; i++){
        cout<<left[i]<<" ";
      }cout<<endl;
      
      return 0;
    }
