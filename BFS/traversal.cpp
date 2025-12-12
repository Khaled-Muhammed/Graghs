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

int n, m, u, v;

vector<int> adj[N];

int dis[N];
void BFS(int src) { // O(n + m)
    dis[src] = 0;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dis[v] == OO) {
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
}
void TheManWhoNeverGivesUp() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dis, OO, sizeof dis);
    BFS(0);
    for (int u = 0; u < n; u++) {
        cout << u << ' ' << dis[u] << el;
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
