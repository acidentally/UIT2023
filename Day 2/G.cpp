/*
Good luck for those who are trying your best
May the most glorious victory come
File name: G.cpp
Code by : acident / lckintrovert
Created since : 15/09/2023 ~~ 08:19:19
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define int                 long long
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

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       2e5 + 10;
int const INF       =       1e9 + 10;

struct Edge {
    int u, v, w, idx;
    Edge() = default;
    Edge(int u_, int v_, int w_, int i_) : u(u_), v(v_), w(w_), idx(i_) {}
    bool operator < (const Edge &e) {
        return w < e.w;
    }
};

vi p;
int find(int k) {
    if(k == p[k]) return k;
    return p[k] = find(p[k]);
}
void connect(int u, int v) {
    u = find(u); v = find(v);
    p[u] = v;
}

bool vis[maxn] = {};
int n, m, MulConst;
int u, v, w, minW = INF, idx, START;
vi couting;
vector<Edge> e;
vector<pi> a[maxn] = {};

bool dfs(int k, int p) {
    vis[k] = true;
    for(auto s : a[k]) {
        if(s.fi == p) continue; //Not revisiting parent
        if(vis[s.fi]) { //If already visited in the DFS ~ found a cycle loop from s.fi back to
                        //s.fi
            START = s.fi;
            couting.pb(s.se); //Keep pushing the route into a vector
            return 1;
        }
        if(dfs(s.fi, k)) { 
            couting.pb(s.se); 
            if(k == START) { //If the current visitting node is the start
                             //We start outputting the answer
                reverse(all(couting)); //Trace back

                cout << minW * minW + MulConst * couting.size() << endl; //The required answer
                cout << START << ' ' << couting.size() << endl;
                for(auto s : couting) cout << s << ' ';
                exit(0);
            }
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> n >> m >> MulConst;
    //DSU initialization
    p.resize(n + 10);
    for(int i = 1; i <= n; i++) p[i] = i;
    //End of DSU initialization

    //Graph Inputting
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        e.pb(Edge(u, v, w, i));
    }
    sort(all(e));
    //End of Graph Input

    //Compute
    for(auto s : e) {
        w = s.w;
        u = find(s.u); v = find(s.v);
        idx = s.idx;
        a[s.u].pb(mp(s.v, idx));
        a[s.v].pb(mp(s.u, idx));
        if(u == v) {
            minW = w;
            dfs(s.v, -1);
        }
        connect(u, v);
    }
    cout << "Poor girl";
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("ginger.INP", "r", stdin);
    freopen("ginger.OUT", "w", stdout);
    #endif //ONLINE JUDGE

    solve();
}

/*A place to scribble thoughts

*/