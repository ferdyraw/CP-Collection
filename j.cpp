#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 105;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    if (k > 3)
    {
        cout << 0 << endl;
    }
    else if (k == 3)
    {
        if (m <= n) cout << 0 << endl;
        else
        {
            int ans = m-n-(m/n-1);
            cout << ans << endl;
        }
    }
    else if (k == 2)
    {
        if (m <= n) cout << m << endl;
        else 
        {
            int ans = 0;
            ans += n;
            ans += m/n-1;
            cout << ans << endl;
        }
    }
    else 
    {
        cout << 1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) solve();
    

    return 0;
}