/*
  You are given a matrix with N rows and M columns. Each cell is either dry or has water.
  We say that two cells are neighbours if they share one of their four sides. A pond is a maximal subset of cells
  containing water such that any cell is accessible from any other cell by moving only along neighbours. 
  You should add water to exactly one cell in order to maximise the size of the pond.

Input Format
  The first line contains two integers N and M. Each of the next N lines contains M integers: 0 for a dry cell 
  and 1 for a cell containing water.

Output Format
  Print a single integer representing the largest possible size of the pond.

link:- https://hack.codingblocks.com/app/contests/1107/244/problem 
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

bool allow=true;

bool vis[1001][1001];
int group_id[1001][1001];
int mat[1001][1001];
static int id=10;
unordered_map<int,int>group_size;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int i, int j, int n, int m, int &count){
  if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || mat[i][j]!=1){
    return;
  }
  
  vis[i][j]=true;
  group_id[i][j] = id;
  count++;

  dfs(i+1, j, n, m, count);
  dfs(i-1, j, n, m, count);
  dfs(i, j+1, n, m, count);
  dfs(i, j-1, n, m, count);

  return;
}

void printMatrix(int arr[][1001], int n, int m){
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  return;
}

int main(){
  if(allow){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(vis, false, sizeof(vis));

  int n,m;  cin>>n>>m;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>mat[i][j];
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(mat[i][j]==1 && vis[i][j]==false){
        int count=0;
        dfs(i, j, n, m, count);
        group_size[id++] = count;
      }
    }
  }

  // printMatrix(mat, n, m);
  // printMatrix(group_id, n ,m);

  int ans=1;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(mat[i][j]==0){
        set<int>s;
        for(int k=0; k<4; k++){
          int x = i + dx[k];
          int y = j + dy[k];

          if(x>=0 && y>=0 && x<n && y<m && mat[x][y]==1){
            s.insert(group_id[x][y]);
          }

        }
        int curr_ans=0;
        for(int x : s){
          curr_ans += group_size[x];
        }
        ans = max(ans, curr_ans+1);
      }
    }
  }

  cout<<ans<<endl;


  return 0;
}


/*
TIP:- Similar to DFS just select one and keep doing DFS till the same type of element keeps appearing.
*/