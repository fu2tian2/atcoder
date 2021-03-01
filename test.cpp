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
#define INF 8000000000000000000 //14
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
ll mod(ll x, ll y) {
    if (x<0) x+=(abs(x)/y)*y+y;
    return x%y;
}

vector<ll> crt1(ll x, ll y) {
    // x*s-y*t=gcd(x,y)となるs,t,gcdを返す
    cout << "test1 " << x << " " << y << endl;
    if (x%y==0) return {1,x/y-1,y};
    auto v = crt1(y,x%y);
    ll s = mod(-v[1],y/v[2]);
    ll t = (x*s-v[2])/y;
    cout << "test2 " << x << " " << y << " " << s << " " << t << endl;
    return {s,t,v[2]};
}

P crt2(ll a, ll b, ll c, ll d) {
    // a mod bかつ、c mod dとなるval mod(lcm(b,d))
    if (abs(c-a)%__gcd(b,d)!=0) return {INF,-1};
    if (b<d) {swap(b,d); swap(a,c);}
    auto v = crt1(b,d);
    ll val = b*v[0]*((c-a)/v[2])+a;
    ll lcm = b*d/v[2];
    // cout << "test" << " " << val << endl;
    val = mod(val,lcm);
    return {val,lcm};
}
P crt(vector<ll> rem, vector<ll> div) {
    // CRT(crt2のn個拡張版)
    ll x = 0; ll y = 1; P v;
    REP(i,rem.size()) {
        if (y<div[i]) {swap(x,rem[i]); swap(y,div[i]);}
        v = crt2(x,y,rem[i],div[i]);
        // cout << i << " " << v.first << " " << v.second << endl;
        if (v.second==-1) return {-1,-1};
        x = v.first; y = v.second;
    }
    return v;
}

int main() {
    ll x, y, s, t; cin >> x >> y >> s >> t;
    auto v = crt1(x,y);
    auto w = crt2(s, x, t, y);
    cout << v[0] << " " << v[1] << " " << v[2] << endl;
    cout << w.first << " " << w.second << endl;
}