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
#define N 110

vector<vector<ll>> dict(N,vector<ll>(N,0));
vector<ll> level(N,-1);
vector<vector<ll>> conn(N);

void test(ll x, string s="") {
    cout << s << endl;
    REP(i,x) {
        REP(j,x) cout << dict[i][j] << " ";
        cout << endl;
    }
    cout << "level: ";
    REP(i,x) cout << level[i] << " ";
    cout << endl;
    return;
}

void calc_dist(ll n) {
    // 根からの距離計算
    REP(i,n) level[i]=-1;
    queue<ll> q;
    q.push(0); level[0]=0;
    while (!q.empty()) {
        ll now = q.front(); q.pop();
        // cout << "test " << now << endl;
        for (ll nex : conn[now]) if (dict[now][nex]>0 && level[nex]==-1) {
                level[nex]=level[now]+1; q.push(nex);
        }
    }
    return;
}

ll send_flow(ll now, ll prev, ll flowForward, ll &n) {
    // cout << "flowForward: " << now << " " << prev << " " << flowForward << endl;
    ll flowBack = 0;
    if (now==n-1) flowBack = flowForward;
    else {
        for (ll nex : conn[now]) if (dict[now][nex]>0 && level[nex]==level[now]+1) {
            ll branchBack = send_flow(nex,now,min(flowForward,dict[now][nex]),n);
        // cout << "ok? " << branchBack << " " << prev << " " << now << endl;
            flowBack += branchBack; flowForward -= branchBack;
        }
    }
    // cout << "flowBack: " << now << " " << prev << " " << flowBack << endl;
    if (prev!=-1) {
        dict[prev][now] -= flowBack;
        dict[now][prev] += flowBack;
    }
    return flowBack;
}

int main(){
    ll n, m; cin >> n >> m;
    REP(i,m) {
        ll u, v, c; cin >> u >> v >> c;
        conn[u].pb(v); conn[v].pb(u);
        dict[u][v]=c;
    }
    ll ans = 0;
    while (true) {
        // 根から終点までいけなくなるまで繰り返す
        //↓根からの距離計算
        calc_dist(n);
        // test(n,"after bfs");
        if (level[n-1]==-1) break;
        ans += send_flow(0,-1,INF,n);
    }
    cout << ans << endl;
    return 0;
}


// test cases
// case-1
// 5 7
// 0 1 10
// 1 2 6
// 0 3 2
// 1 3 6
// 2 3 3
// 2 4 8
// 3 4 5
// ans-1
// 11
// case-2
// 4 5
// 0 1 2
// 0 2 1
// 1 2 1
// 1 3 1
// 2 3 2
// ans-2
// 3