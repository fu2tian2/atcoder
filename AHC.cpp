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
#define N 205
#define D 10010
#define C 100000000

vector<vector<ll>> field(D,vector<ll>(D,0));
vector<set<ll>> eachX(D); // 各x座標に関して埋まってるy座標を持つ
vector<set<ll>> eachY(D); // 各y座標に関して埋まってるx座標を持つ

int main(){
    // input
    ll n; cin >> n;
    vector<vector<ll>> place(n,vector<ll>(5,0));
    vector<vector<ll>> ansl(n,vector<ll>(5,0));
    REP(i,n) {
        cin >> place[i][1] >> place[i][2] >> place[i][3];
        place[i][0]=place[i][3];
        eachX[place[i][1]].insert(place[i][2]);
        eachY[place[i][2]].insert(place[i][1]);
        place[i][4]=i;
    }
    // algorithm
    sort(place.begin(),place.end());
    REP(i,n) {
        ll wx = place[i][1]; ll wy = place[i][2]; ll r = place[i][3]; ll ind = place[i][4];
        if (r==1) {
            ansl[ind]={wx,wy,wx+1,wy+1};
            continue;
        }

        vector<vector<ll>> xl(D,vector<ll>(2,-1)); //各縦列でokな幅
        vector<vector<ll>> yl(D,vector<ll>(2,-1)); //各横列でokな幅
        FORD(ny,wy,0) {
            // すでに自分の列にいたらbreak
            auto testite = eachY[ny].lower_bound(wx);
            // if (i==1 && ny>=5000) cout << (*testite) << " " << ny << " " << wx << endl;
            if ((*testite)==wx && wy!=ny) break;
            eachY[ny].insert(wx);
            auto selfite = eachY[ny].lower_bound(wx);
            // 下限捜索
            if (selfite==eachY[ny].begin()) xl[ny][0]=0;
            else {
                selfite--;
                xl[ny][0]=(*selfite)+1;
            }
            selfite = eachY[ny].upper_bound(wx);
            // 上限捜索
            if (selfite==eachY[ny].end()) xl[ny][1]=10000-1;
            else {
                xl[ny][1]=(*selfite)-1;
            }
            if (ny!=wy) eachY[ny].erase(wx);
            // cout << "test " << ny << " " << xl[ny][0] << " " << xl[ny][1] << endl;
        }
        FORD(ny,wy-1,0) {
            if (xl[ny][0]!=-1) xl[ny][0]=max(xl[ny][0],xl[ny+1][0]);
            if (xl[ny][1]!=-1) xl[ny][1]=min(xl[ny][1],xl[ny+1][1]);
        }

        // とりあえずxlだけ使って
        ll max = 0; ll tmpa=wx; ll tmpb=wy; ll tmpc=wx+1; ll tmpd=wy+1;
        FORD(ny,wy,0) {
            if (xl[ny][0]==-1) continue;
            ll tmpx = (xl[ny][1]-xl[ny][0]+1)*(wy-ny+1);
            // if (ny>=wy-10) {
            //     cout << "testa " << i << " " << tmpx << " " << ny << endl;
            //     cout << xl[ny][0] << " " << xl[ny][1] << endl;
            // }
            if (tmpx>=r) {
                // 答えをセット
                ll tate = r/(wy-ny+1);
                ll tate2 = tate+1;
                if (abs(tate2*(wy-ny+1)-r)<abs(tate*(wy-ny+1)-r)) tate = tate2;
                tmpx = tate*(wy-ny+1);
                if (abs(r-tmpx)<abs(r-max)) {
                    tmpb = ny; tmpd = wy+1;
                    if (xl[ny][0]<=wx-tate+1) {
                        tmpa = wx-tate+1;
                        tmpc = wx+1;
                    }
                    else {
                        tmpa = xl[ny][0];
                        tmpc = xl[ny][0]+tate;
                    }
                }
                max = tmpx;
            }
            else if (abs(r-max)>abs(r-tmpx)) {
                tmpa = xl[ny][0]; tmpb = ny;
                tmpc = xl[ny][1]+1; tmpd = wy+1;
                max = tmpx;
            }
            else continue;
        }
        FOR(ny,wy,9999) {
            if (xl[ny][0]==-1) continue;
            ll tmpx = (xl[ny][1]-xl[ny][0]+1)*(ny-wy+1);
            if (tmpx>=r) {
                // 答えをセット
                ll tate = r/(ny-wy+1);
                ll tate2 = tate+1;
                if (abs(tate2*(ny-wy+1)-r)<abs(tate*(ny-wy+1)-r)) tate = tate2;
                tmpx = tate*(ny-wy+1);
                if (abs(r-tmpx)<abs(r-max)) {
                    tmpb = wy; tmpd = ny+1;
                    if (xl[ny][0]<=wx-tate+1) {
                        tmpa = wx-tate+1;
                        tmpc = wx+1;
                    }
                    else {
                        tmpa = xl[ny][0];
                        tmpc = xl[ny][0]+tate;
                    }
                }
                max = tmpx;
            }
            else if (abs(r-max)>abs(r-tmpx)) {
                tmpa = xl[ny][0]; tmpb = wy;
                tmpc = xl[ny][1]+1; tmpd = ny+1;
                max = tmpx;
            }
            else continue;
        }
        ansl[ind]={tmpa,tmpb,tmpc,tmpd,r};

        FOR(py,tmpb,tmpd-1) {
            eachY[py].insert(tmpa); eachY[py].insert(tmpc-1);
        }
        FOR(px,tmpa,tmpc-1) {
            eachY[tmpb].insert(px);
            eachY[tmpd-1].insert(px);
        }
    }

    // output answer
    for (auto zahyo : ansl) {
        cout << zahyo[0] << " " << zahyo[1] << " " << zahyo[2] << " " << zahyo[3] << endl;
    }
    // 重複がないか確認
    bool jud = true;
    REP(i,ansl.size()) {
        ll sx = ansl[i][0]; ll sy = ansl[i][1];
        ll tx = ansl[i][2]; ll ty = ansl[i][3];
        FOR(f,sx,tx-1)FOR(g,sy,ty-1) {
            if (field[f][g]) {
                // cout << "bad at " << f << " " << g << " " << i << endl;
                jud = false;
            }
            field[f][g]=1;
        }
    }
    if (jud) cout << "YES" << endl;
    else cout << "NO" << endl; 

    // score
    ld score = 0;
    REP(i,ansl.size()) {
        ll calc = (ansl[i][3]-ansl[i][1])*(ansl[i][2]-ansl[i][0]);
        ll ma = max(ansl[i][4],calc);
        ll mi = min(ansl[i][4],calc);
        ld x = ((ld)1-(ld)mi/(ld)ma)*((ld)1-(ld)mi/(ld)ma);
        x = 1-x;
        score+=x;
    }
    score/=n;
    score*=50000000000;
    cout << "score: " << (ll)score << endl;
    return 0;
}