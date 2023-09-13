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


template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
int const maxn      =       2e3 + 5;
int const INF       =       1e9;
int const dx[4] = {1, 0, -1, 0};
int const dy[4] = {0, 1, 0, -1};
struct status {
    short row, col, dir;
    status() = default;
    status(short r, short c, short d) : row(r), col(c), dir(d) {}
} cur, previous;

int row, col, k, sx, sy, ex, ey;
int x_, y_;
bitset<maxn> m[maxn] = {};

int TURNS[maxn][maxn][4] = {};
status TRACE[maxn][maxn][4] = {};

deque<status> q;
string s;

//Start of Graph Decoder
inline char turn(char x) {
    if('0' <= x && x <= '9') return (x - '0');
    if('A' <= x && x <= 'Z') return (x - 'A' + 10);
    if('a' <= x && x <= 'z') return (x - 'a' + 36);
    if(x == '#') return 62;
    if(x == '$') return 63;
}
int cnt, a;
char times = 6;
void computeGraph(void) {
    for(int i = 1; i <= row; i++) {
        cin >> s; cnt = 1;
        for(int j = 0; j < s.size(); j++) {
            a = turn(s[j]);
            times = 6;
            while(times--) {
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
    status cur, v;
    int veloX, veloY;
    while(!q.empty()) {
        cur = q.front(); 
        q.pop_front();

        for(int i = 0; i <= 3; i++) {
            
            veloX = cur.row + dx[(cur.dir + i) % 4];
            veloY = cur.col + dy[(cur.dir + i) % 4];
            v = status(veloX, veloY, (cur.dir + i) % 4);
            if(!exist(veloX, veloY)) continue;

            if(minimize(turns(v), turns(cur) + (i > 0))) {
                trace(v) = cur;
                if(i > 0) q.push_back(v);
                else q.push_front(v);
            }  
        }       
    }
}
//End of BFS 0-1
inline void solve(void) {
    cin >> row >> col >> k;
    cin >> sx >> sy >> ex >> ey; //Start Coords && End Coords
    computeGraph();
    memset(TURNS, (int)(1 << sizeof(int) - 1), sizeof(TURNS));
    for(int i = 0; i <= 3; i++) {
        x_ = sx + dx[i]; y_ = sy + dy[i];
        if(exist(x_, y_)) {
            turns(status(x_, y_, i)) = 0;
            q.push_front(status(x_, y_, i));
        }
    }
    compute(); //BFS 0-1

    //Find the best ending result
    int ans = INF;
    
    for(int i = 0; i <= 3; i++) {
        if(turns(status(ex, ey, i)) < ans) {
            ans = turns(status(ex, ey, i));
            cur = status(ex, ey, i);
        }
    }
    if(ans > k) {cout << -1; return;}
    cout << ans << endl;

    //Start of BackTracing
    vector<pi> couting;
    couting.pb(mp(ex, ey));
    while(turns(cur) > 0) {
        previous = trace(cur); //TRACE[cur.row][cur.col][cur.dir] là một status
        if(cur.dir != previous.dir) {
            couting.pb(mp(previous.row, previous.col));
        } cur = previous;
    } cout << sx << ' ' << sy << endl;
    for(int i = couting.size() - 1; i >= 0; i--) cout << couting[i].fi << ' ' << couting[i].se << endl;
    //End of BackTracing
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
##.#.#..##
.##.##....
S........#
.#.#..###.
..#.F#####
*/

