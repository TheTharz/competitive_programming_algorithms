#include <iostream>
#include <vector>
using namespace std;

bool isValid(int x,int y,int n, int m, vector<vector<bool>>& visited){
    if(x<0 || x>=n || y<0 || y>=m)
      return false;
    if(visited[x][y])
      return false;
    return true;
}

void dfs(int x,int y,int n,int m,vector<vector<bool>>& visited){
  visited[x][y] = true;
  vector<pair<int,int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};
  for(auto move:moves){
    int new_x = x + move.first;
    int new_y = y + move.second;
    if(isValid(new_x,new_y,n,m,visited))
      dfs(new_x,new_y,n,m,visited);
  }
}

int main(){
  int n,m;
  cin >> n >> m ;
  int rooms = 0;
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      char c;
      cin >> c;
      if(c=='#')
        visited[i][j] = true;
      else
        visited[i][j] = false;
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(!visited[i][j]){
        dfs(i,j,n,m,visited);
        rooms++;
      }
    }
  }
  cout << rooms << endl;
}