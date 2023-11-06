#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first 
#define S second

signed main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    int p[105], d[105];
    for (int i = 0; i < n; i++) cin >> p[i];

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<pair<int, int>> v;
        for (int j = 0; j < i; j++) 
        {
            v.push_back({p[j], j});
        }

        sort(v.begin(), v.end());
        memset(d, 0, sizeof(d));

        int ckm = m, ckk = k, sum = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (ckm >= v[j].F)
            {
                ckm -= v[j].F;
                d[v[j].S] = 1;
                sum++;
            }
            else if (ckk > 0)
            {
                d[v[j].S] = 1;
                ckk--;
                sum++;
            }
        }

        bool woi = true;
        for (int j = 0; j < sum; j++)
        {
            if (!d[j]) woi = false;
        }

        if (woi) ans = max(ans, sum);
    }

    cout << ans << endl;
    
    return 0;
}