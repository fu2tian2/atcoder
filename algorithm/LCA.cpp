//ABC14D
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

vector<ll> depth(N); //0から数えた深さ
vector<vector<ll>> par(N); //自分の2**i個上の祖先
vector<vector<ll>> conn(N);

void dfs(ll d, ll x, ll y) { //d:depth, x:nowat, y:parent, depthとpar作成
    depth[x] = d;
    if (y>=0) { //y==-1のときは-1をparに追加しないように
        par[x].pb(y);
        ll i = 0;
        while ((1ll<<(i+1))<=depth[x]) {
            ll pind = par[x][i];
            if (pind!=0) par[x].pb(par[pind][i]); //par[x]にxの2**i個上の親を追加していく
            i++; //parを作るときに自分の祖先のデータを利用する
        }
    }
    REP(i,conn[x].size()) if (conn[x][i]!=y) {
        dfs(d+1, conn[x][i], x);
    }
}

ll finder(ll x, ll d) { //xから距離dにあるnodeをbitで探索
    ll i = 0;
    while (true) {
        if ((d>>i)==0) break;
        if ((d>>i)%2) x = par[x][i]; //dのbitが立ってる分だけ上に移動していく
        i++;
    }
    return x;
}

int main() {
    ll n; cin >> n;
    REP(i,n-1) {ll x, y; cin >> x >> y; x--; y--; conn[x].pb(y); conn[y].pb(x);}
    dfs(0, 0, -1);
    ll q; cin >> q;
    REP(i,q) {
        ll a, b; cin >> a >> b; a--; b--;
        ll ans = 1+abs(depth[a]-depth[b]);
        if (depth[a]>depth[b]) a = finder(a, depth[a]-depth[b]);
        else if (depth[a]<depth[b]) b = finder(b, depth[b]-depth[a]);
        ll l = -1; ll r = depth[a]; //lowest common ancestorを二分探索
        while (r-l>1) {
            ll mid = (l+r)/2;
            if (finder(a, mid)==finder(b, mid)) r = mid;
            else l = mid;
        }
        ans+=2*r;
        cout << ans << endl;
    }
}