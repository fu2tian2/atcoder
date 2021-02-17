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
#define N 210000
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

vector<ll> a(N);
vector<ll> ansl(N,-1); 
vector<vector<ll>> conn(N);
set<ll> s; //今いる位置での最長増加部分列をsに収納する

void dfs(ll l, ll now, ll past) { // lがpastまでの長さ
    if (s.empty()) { //空のときは追加
        s.insert(a[now]); l++; ansl[now]=l;
        REP(i,conn[now].size()) if (conn[now][i]!=past) dfs(l,conn[now][i],now);
        l--; s.erase(a[now]);
        return;
    }
    auto ite = s.rbegin();
    if (*ite<a[now]) { //今見てるnodeの値が最大値の場合は追加
        s.insert(a[now]); l++;
        ansl[now]=l;
        REP(i,conn[now].size()) if (conn[now][i]!=past) dfs(l,conn[now][i],now);
        l--; s.erase(a[now]);
    }
    else { // そうでない場合は列をなるべく小さい数のもので構成するために今のnodeの値を挿入
        auto ite2 = s.lower_bound(a[now]);
        ll x = *ite2;
        s.erase(ite2); s.insert(a[now]);
        ansl[now]=l;
        REP(i,conn[now].size()) if (conn[now][i]!=past) dfs(l,conn[now][i],now);
        s.erase(a[now]); s.insert(x);
    }
    return;
}
int main(){
    ll n; cin >> n;
    REP(i,n) cin >> a[i];
    REP(i,n-1) {
        ll u, v; cin >> u >> v; u--; v--;
        conn[u].pb(v);
        conn[v].pb(u);
    }
    dfs(0,0,-1);
    REP(i,n) cout << ansl[i] << endl;
    return 0;
}