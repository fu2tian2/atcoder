// ABC189C 最大長方形
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
int main(){
  ll n; cin >> n;
  vector<ll> a(n);
  stack<vector<ll>> s;
  REP(i,n) cin >> a[i];
  ll ans = 0;
  REP(i,n) {
    if (a[i]>a[i-1] || s.empty()) s.push({a[i],i});
    else if (a[i]<a[i-1]) {
      ll reminder;
      while (!s.empty()) {
        ll x = s.top()[0];
        ll y = s.top()[1];
        if (x<=a[i]) break;
        // cout << i << " " << x << " " << y << " " << a[i] << endl;
        reminder = y;
        ans = max(ans,x*(i-y));
        s.pop();
      }
      s.push({a[i],reminder});
    }
  }
  while (!s.empty()) {
    ll x = s.top()[0];
    ll y = s.top()[1];
    // cout << x << " " << y << endl;
    ans = max(ans,x*(n-y));
    s.pop();
  }
  cout << ans << endl;
}