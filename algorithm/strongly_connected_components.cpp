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
#define N 11000

vector<vector<pair<ll,bool>>> conn(N);
vector<ll> checked(N,0); // dfs参照
vector<ll> orderList(N,-1); // dfsで通った順番に登録していく
vector<ll> groupList(N,-1); // 各nodeにgroupをつけていく
ll cnt = 0;

void dfs(ll now, ll prev) { 
    // 帰り道に通った順に番号をつける, 重複が起きないように行きにcheckedする
    // orderList[i]はi番のnode
    checked[now]=1;
    for (auto v : conn[now]) {
        // すでに見たところ、親、false(逆向きの枝)
        if (checked[v.first]==1 || v.first==prev || v.second==false) continue;
        dfs(v.first,now);
    }
    // 通った順に番号をつける
    orderList[cnt]=now; cnt++;
    return;
}


void dfs2(ll now, ll group) {
    // nowが今見るnode, groupが登録するgroup番号
    groupList[now]=group;
    for (auto v : conn[now]) {
        // すでにgroup番号が付いてるnode、逆向きでない枝はスルー
        if (groupList[v.first]!=-1 || v.second==true) continue;
        // nowから行けるところに、同じgroup番号をつける
        dfs2(v.first,group);
    }
    return;
}

int main(){
    ll n, m; cin >> n >> m;
    REP(i,m) {
        ll u, v; cin >> u >> v;
        // trueで登録するのは元の向きの枝
        // falseは逆向きの枝(dfs2で用いる)
        conn[u].pb({v,true});
        conn[v].pb({u,false});
    }
    REP(i,n) if (!checked[i]) {
        // 連結グラフでない場合には開始点が複数個必要
        dfs(i,-1);
    }
    FORD(i,n-1,0) {
        // -1のときはそれ以降も全部-1なのでbreak
        // 単独のnodeがある場合は、orderListにn個全部が登録されないので、あまりの枠が出る
        if (orderList[i]==-1) break;
        // すでに見たnodeの場合はgroupListにgroup番号が登録されているので、スルー
        if (groupList[orderList[i]]!=-1) continue;
        // 始点となるnodeの番号をグループ番号とする
        dfs2(orderList[i],orderList[i]);
    }
    ll q; cin >> q;
    REP(i,q) {
        ll u, v; cin >> u >> v;
        // 同じグループに属する場合は1, そうでなければ0
        if (groupList[u]==groupList[v]) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}