#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200005;
int n, x, y, d[N], p[N], ck[N], totalx, totaly, batasx = -1, batasy = -1;
vector<int> adj[N];

void dfs(int u)
{
    for (auto v: adj[u])
    {
        if (d[v] != -1) continue;
        d[v] = d[u]+1;
        p[v] = u;
        dfs(v);
    }
}

void dfsx(int u)
{
    totalx++;
    for (auto v: adj[u])
    {
        if (d[v] != -1) continue;
        if (v == batasy) continue;
        d[v] = d[u]+1;
        dfsx(v);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y; x--, y--;
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    memset(d, -1, sizeof(d));
    memset(p, -1, sizeof(p));

    d[x] = 0;
    dfs(x);

    /* for (int i = 0; i < n; i++)
    {
        if (i) cout << " ";
        cout << d[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (i) cout << " ";
        cout << p[i];
    }
    cout << endl; */

    int dis = (d[y]-1)/2, pu = y;
    while (dis)
    {
        pu = p[pu];
        dis--;
    }
    batasy = pu;
    batasx = p[pu];

    // cout << batasx << " " << batasy << endl;
       
    memset(d, -1, sizeof(d));
    d[x] = 0;
    
    dfsx(x);
    totaly = n-totalx;

    if (totalx == totaly) cout << "Mabar" << endl;
    else if (totalx > totaly) cout << "Kansas" << endl;
    else cout << "Dallas" << endl;

    return 0;
}