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
ll seg[1ll<<20];
ll lazy[1ll<<20];
ll SIZE= 1ll<<19;

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
}

void eval_lazy(ll sl, ll sr, ll pos) {
    if (lazy[pos]==0) return;
    seg[pos*2]=(sr-sl)/2-seg[pos*2];
    seg[pos*2+1]=(sr-sl)/2-seg[pos*2+1];
    lazy[pos*2]^=1;
    lazy[pos*2+1]^=1;
    lazy[pos]=0;
    return;
}

void set_value(ll ql, ll qr, ll sl=0, ll sr=1ll<<20, ll pos=1) {
    if (qr<=sl || sr<=ql) return;
    if (ql<=sl && sr<=qr) {
        seg[pos]=(sr-sl+1)-seg[pos];
        lazy[pos]^=1;
        return;
    }
    eval_lazy(sl,sr,pos);
    ll sm = (sl+sr)/2;
    set_value(ql,qr,sl,sm,pos*2);
    set_value(ql,qr,sm,sr,pos*2+1);
    seg[pos]=seg[pos*2]+seg[pos*2+1];
    return;
}

ll get_tent(ll ql, ll qr, ll sl=0, ll sr=1ll<<20, ll pos=1) {
    if (qr<=sl || sr<=ql) return 0;
    
}

int main(){
    ll n, q; cin >> n >> q;
    REP(i,n) {
        ll a; cin >> a;
        seg[SIZE+i]=a; lazy[SIZE+i]=a;
    }
}