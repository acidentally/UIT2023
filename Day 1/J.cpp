/*
Good luck for those who are trying your best
May the most glorious victory come
File name: J.cpp
Code by : acident / lckintrovert
Created since : 18/09/2023 ~~ 07:57:12
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

typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef pair<int, int>       pi;
typedef pair<int, pi>        pii;
typedef pair<int, set< int, greater<int> > > pis;
int const mod       =       998244353;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;

class Compare {
public:
    bool operator() (pis s1, pis s2) {
        if(s1.se.empty()) return 0;
        if(s2.se.empty()) return 1;
        return *s1.se.begin() > *s2.se.begin();
    }
};
int cmp(set<int, greater<int> > s1, set<int, greater<int> > s2) {
    set<int, greater<int> >::iterator p1 = s1.begin(), p2 = s2.begin();
    while(p1 != s1.end() && p2 != s2.end() && *p1 == *p2) {
        p1++; p2++;
    }
    if(p1 == s1.end() && p2 == s2.end()) return 0; //return 0 khi bằng nhau
    if(p1 == s1.end()) return -1;
    if(p2 == s2.end()) return 1;
    if(*p1 > *p2) return 1;
    return -1;
}
//Dijkstra time
set<int, greater<int> > d[maxn] = {}, du, temp;
int s, t, u, v, dv;
set<int, greater<int> >::iterator ptr;
vector<pi> a[maxn] = {};
void Dijkstra(void) {
    cin >> s >> t;
    d[s].clear();
    priority_queue< pis, vector<pis>, Compare> pq;
    pq.push(mp(s, d[s]));
    while(!pq.empty()) {
        u = pq.top().fi; du = pq.top().se;
        pq.pop();
        if(cmp(du, d[u]) != 0) continue;
        for(auto s : a[u]) {
            temp = d[u];
            v = s.fi; dv = s.se;
            ptr = temp.find(dv);
            while(ptr != temp.end() && *ptr == dv) {
                ptr++;
                temp.erase(dv);
                dv++;
            }
            temp.ins(dv);
            if(cmp(temp, d[v]) == -1) {
                d[v] = temp;
                pq.push(mp(v, d[v]));
            }
        }
    }
    ptr = d[t].begin();
}
//End of Dijkstra

int n, m, c;
int modPow[150010] = {};
void init(){
    modPow[0] = 1;
    for (int i = 1; i <= 150000; i++) (modPow[i] = modPow[i - 1] << 1) %= mod;
    for (int i = 1; i <= n; i++) d[i].ins(200000);
}
inline void solve() {
    //Graph inputting
    cin >> n >> m;
    init();
    while(m--) {
        cin >> u >> v >> c;
        a[u].pb(mp(v, c));
        a[v].pb(mp(u, c));
    }
    //End of graph inputting
    Dijkstra();
    int ans = 0;
    for(auto num : d[t]) {
        (ans += modPow[num]) %= mod;
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef ONLINE_JUDGE
    freopen("Dijkstra.INP", "r", stdin);
    freopen("Dijkstra.OUT", "w", stdout);
    #endif //ONLINE JUDGE
    cin >> n; //(subtast)//
    solve();
}

/*A place to scribble thoughts

*/