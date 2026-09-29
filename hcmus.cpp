#include <bits/stdc++.h>
using namespace std;
const int maxN = 10010;

int n, m;
bool joint[maxN];
int timeDfs = 0, bridge = 0;
int low[maxN], num[maxN];
vector<int> g[maxN];
void dfs(int u, int pre){
    num[u] = low[u] = ++timeDfs;
    for(int v : g[u]){
        if(v == pre)
            continue;
        if(!num[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], num[v]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    fill_n(num, n + 1, false);
    fill_n(low, n + 1, false);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    
    return 0;
}