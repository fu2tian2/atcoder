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
int main(){
    ll n; cin >> n;
    stack<P> s;
    ll ans = 0;
    REP(i,n+1) {
        ll a; 
        if (i==n) a=0; // 最後は高さ0の長方形と見て、後処理を行う
        else cin >> a;
        ll reminder = INF; // x.first>aの時のwhileサイクルでどこまで戻るか記録
        while (true) {
            if (s.empty()) { //空のときは追加
                if (reminder!=INF) s.push({a,reminder});
                else s.push({a,i});
                break;
            }
            auto x = s.top();
            // cout << i << " " << a << " " << x.first << " " << x.second << endl;
            if (x.first<a) {
                if (reminder!=INF) s.push({a,reminder});
                else s.push({a,i});
                break;
            }
            else if (x.first>a) {
                ans = max(ans,(i-x.second)*(x.first));
                s.pop();
                reminder = x.second;
            }
            else break; //x.first==aのときは何もする必要がない
        }
    }
    cout << ans << endl;
}