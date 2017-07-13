#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 100010;

int uf[MAX_N];

void init(int n){
  for(int i = 0;i < n;++i){
    uf[i] = -1;
  }
}

int find(int n){
  if(uf[n] < 0){
    return n;
  }else{
    return uf[n] = find(uf[n]);
  }
}

bool same(int a,int b){
  return find(a) == find(b);
}

void unite(int a,int b){
  int pa = find(a);
  int pb = find(b);
  
  if(pa == pb)return;
  
  if(uf[pa] < uf[pb]){
    uf[pb] = pa;
  }else if(uf[pa] > uf[pb]){
    uf[pa] = pb;
  }else{
    uf[pb] = pa;
    --uf[pa];
  }
}

int main(void){
  int n,q;
  cin >> n >> q;
  init(n);
  for(int i = 0;i < q;++i){
    int c,x,y;
    cin >> c >> x >> y;
    if(c == 0){
      unite(x,y);
    }else{
      if(same(x,y)){
        puts("1");
      }else{
        puts("0");
      }
    }
  }
  return 0;
}
