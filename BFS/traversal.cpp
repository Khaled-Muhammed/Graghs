#include <bits/stdc++.h>
#define int long long
#define el '\n'
#define all(x) x.begin(), x.end()
#define MOD 1'000'000'007;
using namespace std;
//====================//

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dx_all[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy_all[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e5 + 5, M = 2e5 + 5, OO = 0x3f3f3f3f;

int n, m;
vector<int> adj[N];
int dis[N];

void BFS(int src) {

    fill(dis, dis + n, OO);   
    queue<int> q;
    dis[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dis[v] == OO) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}

void TheManWhoNeverGivesUp() {

    cin >> n >> m;
    for (int i = 0; i < n; ++i) adj[i].clear();

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS(0);

    for (int u = 0; u < n; ++u) {
        cout << u << ' ' << dis[u] << '\n';
    }
}
signed main() {

//    std::freopen("longpath.in", "r", stdin);
//    std::freopen("longpath.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    file();

    int tc = 1;
    //cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        //  cout<<"Case #"<<i<<": ";
        TheManWhoNeverGivesUp();
    }
}
/*
Input
9 13
0 1
0 2
0 3
0 7
1 6
2 6
3 5
7 8
7 6
6 4
5 6
5 8
6 8

Output
0 0
1 1
2 1
3 1
4 3
5 2
6 2
7 1
8 2
*/
