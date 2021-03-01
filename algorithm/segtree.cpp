// AOJ RMQ
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

ll seg[1ll<<20];
ll SIZE = 1ll<<19;
ll INFL = (1ll<<31)-1;

void set_val(ll at, ll val, ll sl=0, ll sr=1ll<<19, ll pos=1) {
    if (at<sl || sr<=at) return;
    if (pos>=(1ll<<19)) seg[pos]=val;
    else {
        ll sm = (sl+sr)/2;
        set_val(at,val,sl,sm,pos*2);
        set_val(at,val,sm,sr,pos*2+1);
        seg[pos]=min(seg[pos*2],seg[pos*2+1]);
    }
    return;
}

ll get_min(ll ql, ll qr, ll sl=0, ll sr=1ll<<19, ll pos=1) {
    if (sr<=ql || qr<=sl) return INF;
    if (ql<=sl && sr<=qr) return seg[pos];
    ll sm = (sl+sr)/2;
    ll lmin = get_min(ql,qr,sl,sm,pos*2);
    ll rmin = get_min(ql,qr,sm,sr,pos*2+1);
    return min(lmin,rmin);
}


int main(){
    ll n, q; cin >> n >> q;
    REP(i,SIZE*2) seg[i]=INFL;
    REP(i,q) {
        ll c, x, y; cin >> c >> x >> y;
        if (c==0)  set_val(x,y);
        else cout << get_min(x,y+1) << endl;
    }
    return 0;
}