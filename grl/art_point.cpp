#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int MAX_N = 100010;

int ord[MAX_N],low[MAX_N],parent[MAX_N];
bool visited[MAX_N];
vector< vector< int> > G;
set< int > ap;

void dfs(int now,int prev,int &cnt){
  visited[now] = true;
  ord[now] = cnt;
  low[now] = cnt;
  parent[now] = prev;
  ++cnt;
  for(int i : G[now]){
    if(!visited[i]){
      dfs(i,now,cnt);
      low[now] = min(low[now],low[i]);
    }else if(i != prev){
      low[now] = min(low[now],ord[i]);
    }
  }
}

void find_ap(int node_size){
  fill(ord,ord+MAX_N,-1);
  fill(low,low+MAX_N,-1);
  fill(parent,parent+MAX_N,-1);
  for(int i = 0;i < node_size;++i)
    visited[i] = false;
  ap.clear();
  
  int cnt = 0;
  int root = 0;
  dfs(root,-1,cnt);
  int root_child = 0;
  for(int i = 1;i < node_size;++i){
    if(parent[i] == root){
      ++root_child;
    }else if(ord[parent[i]] <= low[i]){
      ap.insert(parent[i]);
    }
  }
  if(root_child > 1)ap.insert(root);
}

int main(void){
  int v,e;
  cin >> v >> e;
  G.clear();
  G.resize(v);
  for(int i = 0;i < e;++i){
    int s,t;
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  find_ap(v);
  for(int i : ap){
    cout << i << endl;
  }
  return 0;
}
