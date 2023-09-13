/*
Good luck for those who are trying your best
May the most glorious victory come
File name: F.cpp
Code by : acident / lckintrovert
Created since : 13/09/2023 ~~ 09:12:00
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
// #define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define endl                '\n'
#define pb                  push_back
#define pf                  push_front
#define eb                  emplace_back
#define ins                 insert
#define mp                  make_pair
#define all(a)              a.begin(), a.end()
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define coutdub(x)          cout << fixed << setprecision(x)
#define cerrdub(x)          cerr << fixed << setprecision(x)
 
//#define _USE_MATH_DEFINES // If meth .__.


template<class T1, class T2> void maximize(T1& a, T2 b) {a = max(a, b);}
// template<class T1, class T2> void minimize(T1& a, T2 b) {a = min(a, b);}
template<class T1> T1 abs(T1 a) {return max(a, -a);}
template<class T1, class T2> bool minimize(T1& a, T2 b) {
    if(b < a) {
        swap(a, b);
        return 1;
    } return 0;
}
 
typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
typedef pair<int, char>     pic;
int const mod       =       1e9 + 7;
int const maxn      =       2e3 + 10;
int const INF       =       1e9;
int const dx[4] = {1, 0, -1, 0};
int const dy[4] = {0, 1, 0, -1};
struct status {
    int row, col, dir;
    status() = default;
    status(int r, int c, int d) : row(r), col(c), dir(d) {}
};

int row, col, k;
int sx, sy, ex, ey;
bool m[maxn][maxn] = {};
int TURNS[maxn][maxn][4] = {};
status TRACE[maxn][maxn][4] = {};
deque<status> q;
string s;



//Start of Graph Decoder
int turn(char x) {
    if('0' <= x && x <= '9') return (x - '0');
    if('A' <= x && x <= 'Z') return (x - 'A' + 10);
    if('a' <= x && x <= 'z') return (x - 'a' + 36);
    if(x == '#') return 62;
    if(x == '$') return 63;
}
void outputGraph(void) {
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            if(i == sx && j == sy) {
                cout << 'S'; continue;
            }
            if(i == ex && j == ey) {
                cout << 'F'; continue;
            }
            cout << ((m[i][j]) ? '#' : '.');
        } cout << endl;
    }
}
void computeGraph(void) {
    for(int i = 1, cnt; i <= row; i++) {
        cin >> s; cnt = 1;
        for(int j = 0, c; j < s.size(); j++) {
            int a = turn(s[j]);
            for(int k = 1; k <= 6; k++) {
                m[i][cnt++] = (a & 1);
                a >>= 1;
            }
        }
    }
}
//End of Graph Decoder

#define turns(x)            TURNS[x.row][x.col][x.dir]
#define trace(x)            TRACE[x.row][x.col][x.dir]
//BFS 0-1
bool exist(int x, int y) {
    return (1 <= x && x <= row && 1 <= y && y <= col && !m[x][y]);
}
void compute(void) {
    while(!q.empty()) {
        status cur = q.front(); 
        q.pop_front();

        for(int i = 0; i <= 3; i++) {
            
            int veloX = cur.row + dx[(cur.dir + i) % 4];
            int veloY = cur.col + dy[(cur.dir + i) % 4];

            if(!exist(veloX, veloY)) continue;
            
            status v = status(veloX, veloY, (cur.dir + i) % 4);
            if(minimize(turns(v), turns(cur) + (i > 0))) {
                trace(v) = cur;
                if(i > 0) q.push_back(v);
            }  
            else q.push_front(v);
        }       
    }
}
//End of BFS 0-1
void solve(void) {
    cin >> row >> col >> k;
    cin >> sx >> sy >> ex >> ey;
    computeGraph();
    outputGraph();
    memset(TURNS, 0x3f, sizeof(TURNS));
    for(int i = 0; i <= 3; i++) {
        int x_ = sx + dx[i], y_ = sy + dy[i];
        if(exist(x_, y_)) {
            status s(x_, y_, i);
            turns(s) = 0;
            q.push_front(s);
        }
    }
    // compute();
    int ans = 0;
    status cur;
    for(int i = 0; i <= 3; i++) {
        status ehehe(ex, ey, i);
        if(turns(ehehe) > ans) {
            ans = turns(ehehe);
            cur = ehehe;
        }
    }
    if(ans > k) {
        cout << -1;
        return;
    }
    cout << ans << endl;
    vector<pi> couting;
    couting.pb(mp(ex, ey));
    while(turns(cur) > 0) {
        status previous = trace(cur);
        if(cur.dir != previous.dir) {
            couting.pb(mp(previous.row, previous.col));
        } cur = previous;
    } couting.pb(mp(sx, sy));
    reverse(all(couting));
    for(auto s : couting) cout << s.fi << ' ' << s.se << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("gotoschool.INP", "r", stdin);
    freopen("gotoschool.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    solve();
}

/*A place to scribble thoughts

*/