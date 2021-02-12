#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //int:2*10**9
typedef long double ld;
typedef pair<ll,ll> P;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define vec2(name,i,j,k) vector<vector<ll>> name(i,vector<ll>(j,k))
#define vec3(name,i,j,k,l) vector<vector<vector<ll>>> name(i,vector<vector<ll>>(j,vector<ll>(k,l)))
#define pb push_back
#define MOD 1000000007 //998244353
#define PI 3.141592653
#define INF 100000000000000 //14
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

ll seg[1<<20]; ll lazy[1<<20];
ll SIZE = 1LL<<19;

void eval(ll pos) {
  if (pos<SIZE) {
    lazy[pos*2]+=lazy[pos]; seg[pos*2]+=lazy[pos];
    lazy[pos*2+1]+=lazy[pos]; seg[pos*2+1]+=lazy[pos];
    lazy[pos]=0;
  }
  return;
}

void set_value(ll ql, ll qr, ll x, ll sl=0, ll sr=1ll<<19, ll pos=1) {
  // cout << ql << " " << qr << " " << x << " " << sl << " " << sr << " " << pos << endl;
  if (sr<=ql || qr<=sl) return;
  if (ql<=sl && sr<=qr) {
    // cout << "test2 " << seg[pos] << " " << lazy[pos] << endl;
    seg[pos]+=x; lazy[pos]+=x;
  }
  else {
    // cout << "test3" << endl;
    ll sm = (sl+sr)/2;
    eval(pos);
    set_value(ql,qr,x,sl,sm,pos*2);
    set_value(ql,qr,x,sm,sr,pos*2+1);
  }
  return;
}

ll get_min(ll ql, ll qr, ll sl=0, ll sr=1ll<<19, ll pos=1) {
  cout << ql << " " << qr << " " << sl << " " << sr << " " << pos << endl;
  eval(pos);
  if (sr<=ql || qr<=sl) return INF;
  if (ql<=sl && sr<=qr) return seg[pos];
  ll sm = (sl+sr)/2;
  ll lmin = get_min(ql,qr,sl,sm,pos*2);
  ll rmin = get_min(ql,qr,sm,sr,pos*2+1);
  return min(lmin,rmin);
}

int main(){
  ll n, q; cin >> n >> q;
  REP(i,1<<20) {seg[i]=0; lazy[i]=0;}
  REP(i,q) {
    ll c; cin >> c;
    if (c==0) {
      ll s, t, x; cin >> s >> t >> x;
      set_value(s,t+1,x);
      FOR(i,1<<16,1<<16) cout << seg[i] << " ";
      cout << endl;
      FOR(i,1<<17,1+(1<<17)) cout << seg[i] << " ";
      cout << endl;
      FOR(i,1<<18,3+(1<<18)) cout << seg[i] << " ";
      cout << endl;
      FOR(i,1<<19,7+(1<<19)) cout << seg[i] << " ";
      cout << endl;
      FOR(i,1<<16,1<<16) cout << lazy[i] << " ";
      cout << endl;
      FOR(i,1<<17,1+(1<<17)) cout << lazy[i] << " ";
      cout << endl;
      FOR(i,1<<18,3+(1<<18)) cout << lazy[i] << " ";
      cout << endl;
      FOR(i,1<<19,7+(1<<19)) cout << lazy[i] << " ";
      cout << endl;
    }
    else {
      ll s,t; cin >> s >> t;
      cout << get_min(s,t+1) << endl;
      FOR(i,1<<16,1<<16) cout << seg[i] << " ";
      cout << endl;
      FOR(i,1<<17,1+(1<<17)) cout << seg[i] << " ";
      cout << endl;
      FOR(i,1<<18,3+(1<<18)) cout << seg[i] << " ";
      cout << endl;
      FOR(i,1<<19,7+(1<<19)) cout << seg[i] << " ";
      cout << endl;
      FOR(i,1<<16,1<<16) cout << lazy[i] << " ";
      cout << endl;
      FOR(i,1<<17,1+(1<<17)) cout << lazy[i] << " ";
      cout << endl;
      FOR(i,1<<18,3+(1<<18)) cout << lazy[i] << " ";
      cout << endl;
      FOR(i,1<<19,7+(1<<19)) cout << lazy[i] << " ";
      cout << endl;
    }
  }
}