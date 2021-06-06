#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //int:2*10**9
typedef long double ld;
typedef pair<ll,ll> P;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007 //998244353
#define PI 3.141592653
#define INF 100000000000000 //14
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

vector<ll> typhoon(N,vector<ll>(2))
vector<vector<ll>> queries(N,vector<ll>(3)); // place, index, b/f
vector<ll> ansl(N,0);

void add_cnt(ll ql, ll qr, ll sl = 0, ll sr = 1ll<<19, ll pos = 1) {

}

ll get_sum(ll q, ll sl = 0, ll sr = 1ll<<19, ll pos = 1) {

}


int main(){
    ll n, m, k; cin >> n >> m >> k;
    REP(i,n) cin >> typhoon[i][0] >> typhoon[i][1];
    REP(i,m) {
        ll p, q, r; cin >> p >> q >> r; p--; q--; r--;
        queries[q].pb({p,i,0});
        queries[r].pb({p,i,1});
    }
    REP(i,n) {
        add_cnt(typhoon[i][0],typhoon[i][1]+1);
        for (auto v : queries[i]){
            ll val = get_sum(v[0]);
            if (v[2]==1) ansl[v[1]]+=val;
            else ansl[v[1]]-=val;
        }
    }
    REP(i,m) cout << ansl[i] << endl;
    return 0;
}