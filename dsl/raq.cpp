#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = (1 << 21) - 1;
const int inf = numeric_limits<int>::max();

ll tree[MAX_N];

// call init(0,0,n) to init
// node k => [l,r)
void init(int k,int l,int r){
  if(r - l == 1){
    tree[k] = 0; // init leaf
  }else{
    int chl = k*2+1;
    int chr = k*2+2;
    tree[k] = 0; // init internal-node
    init(chl, l, (l+r)/2);
    init(chr, (l+r)/2, r);
  }
}

// call add(a,b,x,0,0,n) to add
// node k => [l,r)
void add(int a,int b,int x,int k,int l, int r){
  // not cross
  if(r <= a || b <= l)return;
  else if(a <= l && r <= b){
    // [a,b) contain [l,r)
    tree[k] += x;
  } else{
    // otherwise
    int chl = k*2+1;
    int chr = k*2+2;
    add(a,b,x,chl,l,(l+r)/2);
    add(a,b,x,chr,(l+r)/2,r);
  }
}

// call get(i,0,0,n) to get i
// node k => [l,r)
int get(int i,int k,int l,int r){
  ll res = tree[k];
  if(r - l > 1){
    int chl = k*2+1;
    int chr = k*2+2;
    if(i < (l+r)/2){
      res += get(i,chl,l,(l+r)/2);
    }else{
      res += get(i,chr,(l+r)/2,r);
    }
  }
  return res;
}

int main(void){
  int n,q;
  cin >> n >> q;
  init(0,0,n);
  for(int i = 0;i < q;++i){
    int c;
    cin >> c;
    if(c == 0){
      int s,t,x;
      cin >> s >> t >> x;
      add(s-1,t,x,0,0,n);
    }else{
      int i;
      cin >> i;
      cout << get(i-1,0,0,n) << endl;
    }
  }
  return 0;
}
