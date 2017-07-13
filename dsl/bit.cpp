#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = (1 << 21) - 1;
const int inf = numeric_limits<int>::max();

/* /// 1-indexed /// */
ll bit[MAX_N + 1],n;

void add(int i,int x){
  while(i <= n){
    bit[i] += x;
    i += i & -i;
  }
}

ll sum(int i){
  int s = 0;
  while (i > 0){
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

int main(void){
  int q;
  cin >> n >> q;
  fill(bit,bit+MAX_N+1,0);
  for(int i = 0;i < q;++i){
    int c;
    cin >> c;
    if(c == 0){
      int i,x;
      cin >> i >>  x;
      add(i,x);
    }else{
      int s,t;
      cin >> s >> t;
      cout << sum(t) - sum(s-1) << endl;
    }
  }
  return 0;
}
