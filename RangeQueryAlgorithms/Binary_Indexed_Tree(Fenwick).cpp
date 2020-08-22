  /*
    PROBLEM STATEMENT IS LIKE :- 
    Query1:- Given a index update char in string.
    Query2:- Given a range L to R, find that is it possible to make palindrome with the chars present
            in this range.
    
    Problem link:- https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/shil-and-palindrome-research/description/
  */

  #include<bits/stdc++.h>
  using namespace std;

  int BIT[26][100001];

  void update(int val, int index, int n, int cnt){
    while (index <= n){
      BIT[val][index] += cnt;
      index = index + (index &(-index));
    }
    return;
  }

  int query(int val, int l, int r){
    int count =0;
    while(r>0){
        count += BIT[val][r];
        r = r - (r & (-r));
    }

    l--;
    while(l>0){
        count += BIT[val][l];
        l = l - (l & (-l));
    } 
    return count;
  }

  int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n,m;  cin>>n>>m;
    string s; cin>>s;

    for(int i=0; i<s.size(); i++){
      update(s[i]-'a', i+1, n, 1);
    }

    for(int i=0; i<m; i++){
      int q;  cin>>q;
      if(q==1){
        int id; cin>>id;
        char c; cin>>c;
        char d = s[id-1];
        update(d-'a', id, -1);
        update(c-'a', id, 1);
      }
      else{
        int l,r;  cin>>l>>r;
        int res[26] = {0};

        for(int i=0; i<26; i++){
          res[i] = query(i, l, r);
        }

        int ans=0;
        for(int i=0; i<26; i++){
            if(res[i]%2)
              ans++;
        }

        if(ans>1)
          cout<<"no\n";
        else if(ans==1){
          if((r-l+1)%2==1)
            cout<<"yes\n";
          else
            cout<<"no\n";
        }
        else{
          cout<<"yes\n";
        }


      }
    }


  }