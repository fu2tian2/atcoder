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
  set<vector<ll>> s;
  ll n; cin >> n;
  REP(i,n) s.insert({i,n-i});
  for (auto ite=s.begin();ite!=s.end();ite++) {
    cout << "test1" << endl;
    for (auto ite2=s.begin();ite2!=s.end();ite2++) {
      cout << (*ite2)[0] << " " << (*ite2)[1] << endl;
    }
    cout << "now " << (*ite)[0] << " " << (*ite)[1] << endl;
    if ((*ite)[0]==3) {
      s.erase(ite);
      ite++;
    }
    cout << "test2" << endl;
    for (auto ite2=s.begin();ite2!=s.end();ite2++) {
      cout << (*ite2)[0] << " " << (*ite2)[1] << endl;
    }
    cout << "now " << (*ite)[0] << " " << (*ite)[1] << endl;
  }
}