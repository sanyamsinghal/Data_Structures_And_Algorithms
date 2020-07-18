  /*




  */

      #include <bits/stdc++.h>
      using namespace std;

      typedef long long ll;
      #define mod 100000005

      bool allow = true;
      int mat[1001][1001];
      map<string, string>parent;
      map<string, int>comp_size;
      int total_components;

      int dir[][2] = {{0,1}, {0,-1}, {1, 0}, {-1,0}};

      string ts(int x){
        return to_string(x);
      }

      string superparent(int i, int j){
        if(parent[ts(i)+ts(j)]==ts(i)+ts(j))
          return ts(i)+ts(j);
        else{
          parent[ts(i)+ts(j)] = superparent(i,j);
          return parent[ts(i)+ts(j)];
        }
      }

      void unite(int i, int j, int x, int y){
        string spij = superparent(i,j);
        string spxy = superparent(x,y);

        if(spij==spxy)
          return;
        
        parent[spij] = spxy;
        total_components--;
        comp_size[spxy] += comp_size[spij];
        return;
      }

      int main() {
        if(allow){
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        }
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n,m;  cin>>n>>m;
        total_components = n*m;
        for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
            cin>>mat[i][j];
            parent[ts(i)+ts(j)] = ts(i)+ts(j);
            comp_size[ts(i)+ts(j)] = 1;
          }
        }


        int ans=0;
        for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
            if(mat[i][j]==1){
              for(int d=0; d<4; d++){
                int x = i + dir[d][0];
                int y = j + dir[d][1];
                if(x>=0 && y>=0 && x<n && y<m && mat[x][y]==1){
                  unite(i, j, x, y);
                }
              }
            }
          }
        }

        for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
            if(mat[i][j]==0){
              set<string>v;
              for(int d=0; d<4; d++){
                int x = i + dir[d][0];
                int y = j + dir[d][1];
                if(x>=0 && y>=0 && x<n && y<m && mat[x][y]==1){
                    v.insert(superparent(x,y));
                }
              }

              int curr_ans=0;
              for(string x : v){
                curr_ans += comp_size[x];
                // cout<<x.first<<","<<x.second<<"  ";
              }
              // cout<<endl;
              ans = max(ans, curr_ans+1);
              // cout<<i<<" "<<j<<" "<<(curr_ans+1)<<endl;
            }
          }
        }

        for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
            string p = superparent(i,j);
            // cout<<i<<","<<j<<"->";
            // cout<<p.first<<" "<<p.second<<endl;
            // cout<<"componenet soze "<<comp_size[p]<<endl;
          }
        }


        cout<<ans<<endl;


        return 0;
      }
