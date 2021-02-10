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
  ll n, m; cin >> n >> m;
  vector<vector<ll>> con(m,vector<ll>(2));
  REP(i,m) {
    ll x, y; cin >> x >> y;x--;y--;
    con[i][0]=x;con[i][1]=y;
  }
  ll k; cin >> k;
  vector<vector<ll>> cho(k,vector<ll>(2));
  REP(i,k) {
    ll x, y; cin >> x >> y;x--;y--;
    cho[i][0]=x;cho[i][1]=y;
  }
  ll ans = 0;
  REP(i,1ll<<k) {
    vector<ll> cnt(n,0);
    REP(j,k) {
      if ((i>>j)%2) cnt[cho[j][1]]++;
      else cnt[cho[j][0]]++;
    }
    ll ansc = 0;
    REP(j,m) {
      if (cnt[con[j][0]] && cnt[con[j][1]]) ansc++;
    }
    ans = max(ans,ansc);
  }
  cout << ans << endl;
}