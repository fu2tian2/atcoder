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
#define N 110000
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
ll n, m, k;
vector<vector<ll>> conn(N);
vector<vector<ll>> dist(k,vector<ll>(k,INF));

vector<ll> dijkstra(ll x) {
  vector<ll> adist(N,INF);
  queue<ll> q;
  q.push(x); adist[x]=0;
  while (!q.empty()) {
    auto now = q.front(); q.pop();
    for (auto to: conn[now]) {
      if (adist[to]==INF) {
        adist[to]=adist[now]+1;
        q.push(to);
      }
    }
  }
  return adist;
}

int main(){
  cin >> n >> m;
  REP(i,m) {
    ll a, b; cin >> a >> b;a--;b--;
    conn[a].pb(b);conn[b].pb(a);
  }
  cin >> k;
  vector<ll> c(k);
  REP(i,k) {
    cin >> c[i]; c[i]--;
  }
  dist = vector<vector<ll>>(k,vector<ll>(k,INF));
  REP(i,k) {
    auto adist = dijkstra(c[i]);
    REP(j,k) {
      // cout << i << " " << j << endl;
      // cout << "test-1 " << dist[0][0] << endl;
      // cout << "test0 " << dist[i][j] << endl;
      // cout << "test1 " << adist[c[j]] << endl;
      dist[i][j]=adist[c[j]];
      if (dist[i][j]==INF) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  // cout << "test3" << endl;
  vector<vector<ll>> dp((1ll<<k),vector<ll>(k,INF));
  REP(i,k) dp[1ll<<i][i]=1;
  // cout << "test4" << endl;
  REP(bit,1ll<<k) {
    REP(nex,k) {
      REP(now,k) {
        dp[bit|(1ll<<nex)][nex]=min(dp[bit|(1ll<<nex)][nex],dp[bit][now]+dist[now][nex]);
      }
    }
  }
  // cout << "test5" << endl;
  ll ans = INF;
  REP(i,k) ans = min(ans,dp[(1ll<<k)-1][i]);
  cout << ans << endl;
}