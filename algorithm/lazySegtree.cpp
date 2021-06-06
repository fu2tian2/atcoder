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
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

// AOJ RMQ ans RUQ

ll seg[1ll<<20]; ll lazy[1ll<<20];
ll SIZE = 1ll<<19;
ll INF = (1ll<<31)-1;

void segtree_debug(ll x=0, char y= 'a') {
    cout << 's' << y << ' ' << x << endl;
    FOR(i,(1<<16),(1<<16)) cout << seg[i] << ' ';
    cout << endl;
    FOR(i,(1<<17),(1<<17)+1) cout << seg[i] << ' ';
    cout << endl;
    FOR(i,(1<<18),(1<<18)+3) cout << seg[i] << ' ';
    cout << endl;
    FOR(i,(1<<19),(1<<19)+7) cout << seg[i] << ' ';
    cout << endl;
    cout << 'l' << y << ' ' << x << endl;
    FOR(i,(1<<16),(1<<16)) cout << lazy[i] << ' ';
    cout << endl;
    FOR(i,(1<<17),(1<<17)+1) cout << lazy[i] << ' ';
    cout << endl;
    FOR(i,(1<<18),(1<<18)+3) cout << lazy[i] << ' ';
    cout << endl;
    FOR(i,(1<<19),(1<<19)+7) cout << lazy[i] << ' ';
    cout << endl;
    return;
}

void set_value(ll ql, ll qr, ll x, ll sl=0, ll sr=1ll<<19, ll pos=1) {
    // cout << sl << " " << sr << endl;
    if (qr<=sl || sr<=ql) return;
    if (ql<=sl && sr<=qr) {
        seg[pos]=lazy[pos]=x;
        return;
    }
    if (lazy[pos]!=INF) {
        lazy[pos*2]=seg[pos*2]=lazy[pos];
        lazy[pos*2+1]=seg[pos*2+1]=lazy[pos];
    }
    lazy[pos]=INF;
    ll sm = (sl+sr)/2;
    set_value(ql,qr,x,sl,sm,pos*2);
    set_value(ql,qr,x,sm,sr,pos*2+1);
    seg[pos]=min(seg[pos*2],seg[pos*2+1]);
    return;
}

ll get_min(ll ql, ll qr, ll sl=0, ll sr=1ll<<19, ll pos=1) {
    if (qr<=sl || sr<=ql) return INF;
    if (ql<=sl && sr<=qr) return seg[pos];
    if (lazy[pos]!=INF) {
        lazy[pos*2]=seg[pos*2]=lazy[pos];
        lazy[pos*2+1]=seg[pos*2+1]=lazy[pos];
    }
    lazy[pos]=INF;
    ll sm = (sl+sr)/2;
    ll lmin = get_min(ql,qr,sl,sm,pos*2);
    ll rmin = get_min(ql,qr,sm,sr,pos*2+1);
    return min(lmin,rmin);
}

int main(){
    ll n, q; cin >> n >> q;
    REP(i,SIZE*2) {
        seg[i]=INF; lazy[i]=INF;
    }
    REP(i,q) {
        ll c, s, t; cin >> c >> s >> t;
        if (c==0) {
            ll x; cin >> x;
            set_value(s,t+1,x);
            // segtree_debug();
        }
        else {
            ll ans = get_min(s,t+1);
            // segtree_debug();
            cout << ans << endl;
        }
    }
    return 0;
}