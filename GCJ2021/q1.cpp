// GCJ Reversort
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

void solve(ll i) {
    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    REP(i,n) cin >> a[i];
    ll ans = 0;
    REP(i,n-1) {
        ll minValue = a[i]; ll minInd = i;
        FOR(j,i,n-1) {
            if (minValue>a[j]) {
                minValue = a[j];
                minInd = j;
            }
        }
        REP(j,n) {
            if (j<i || minInd<j) b[j]=a[j];
            else b[j]=a[minInd+i-j];
        }
        ans += minInd-i+1;
        a = b;
        // REP(j,n) cout << a[j] << " ";
        // cout << endl;
    }
    cout << "Case #" << i+1 << ": " << ans << endl;
    return;
}
int main(){
    ll t; cin >> t;
    REP(i,t) solve(i);
    return 0;
}