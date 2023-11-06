#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

const int N = 100005;
int n, m, b[N];
pair<int, int> a[N];
multiset<int> s;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.S == b.S) return a.F < b.F;
    return a.S > b.S;
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i].F >> a[i].S;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        s.insert(b[i]);
    }

    sort(a, a+n, comp);
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = s.lower_bound(a[i].F);
        if (it == s.end()) continue;
        ans += a[i].S;
        //cout << *it << endl;
        s.erase(it);
    }

    cout << ans << endl;
    
    return 0;
}