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
#define N 524288
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
int main(){
  ll n; cin >> n;
  vector<ll> a(n);
  vector<ll> b(2*N,0);
  REP(i,n) cin >> a[i];
  ll ans = 0;
  REP(i,n) {
    ll ind = a[i]+N+1;
    // FOR(j,N/2,N/2+1) cout << b[j] << " ";
    // cout << endl;
    // FOR(j,N,N+n-1) cout << b[j] << " ";
    // cout << endl;
    ll y = 2*N;
    while (y-ind>0) {
      if (y%2) {
        ans += b[ind];
        y--;
      }
      y/=2;
      if (ind%2) {
        // cout << "plus " <<  ind << endl;
        ans += b[ind];
        ind++;
      }
      ind/=2;
    }
    ind = a[i]+N;
    while (ind>0) {
      b[ind]++;
      ind/=2;
    }
    // cout << i << " " << ans << endl;
  }
  REP(i,n) {
    if (i==0) cout << ans << endl;
    else {
      ll x = a[i-1];
      ans += n-x-x-1;
      cout << ans << endl;
    }
  }
}