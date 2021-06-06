// GCJ median sort
// cout.flush()
// python3 interactive_runner.py python3 testing_tool.py 0 -- ./a.out
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

void solve(ll n) {
    vector<ll> pos;
    cout << 1 << " " << 2 << " " << 3 << endl; cout.flush();
    ll mid; cin >> mid;
    if (mid==1) pos={-INF,3,1,2,INF};
    else if (mid==2) pos={-INF,1,2,3,INF};
    else pos={-INF,1,3,2,INF};
    ll cnt = 3;
    while (cnt<n) {
        ll val = cnt+1;
        ll lm = 0; ll rm = cnt+1;
        ll l = (2*lm+rm)/3; ll r = (lm+2*rm)/3;
        while (rm-lm>2) {
            cout << pos[l] << " " << pos[r] << " " << val << endl; cout.flush();
            ll mid; cin >> mid;
            if (mid==pos[l]) {
                lm = lm; rm = l;
            }
            else if (mid==pos[r]) {
                lm = r; rm = rm;
            }
            else {
                lm = l; rm = r;
            }
            l = (2*lm+rm)/3; r = (lm+2*rm)/3;
        }
        if (rm-lm==1) {
            pos.insert(pos.begin()+lm+1,val);
        }
        else if (lm!=0) {
            cout << pos[lm] << " " << pos[lm+1] << " " << val << endl; cout.flush();
            ll mid; cin >> mid;
            if (mid==pos[lm+1]) pos.insert(pos.begin()+lm+2,val);
            else pos.insert(pos.begin()+lm+1,val);
        }
        else {
            cout << pos[lm+1] << " " << pos[lm+2] << " " << val << endl; cout.flush();
            ll mid; cin >> mid;
            if (mid==pos[lm+1]) pos.insert(pos.begin()+lm+1,val);
            else pos.insert(pos.begin()+lm+2,val);
        }
        cnt++;
    }
    FOR(i,1,n) cout << pos[i] << " ";
    cout << endl; cout.flush();
    ll jud; cin >> jud;
    if (jud) return;
    return;
}

int main(){
    ll t, n, q; cin >> t >> n >> q;
    REP(i,t) solve(n);
    return 0;
}