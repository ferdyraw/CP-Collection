#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    string s[105], t[105];
    for (int i = 0; i < n; i++) cin >> s[i] >> t[i];

    map<string, int> mp;
    for (int i = 0; i < m; i++) mp[t[i]]++;

    vector<string> ans;
    for (int i = m; i < n && ans.size() < k; i++)
    {
        if (mp.find(t[i]) == mp.end())
        {
            ans.push_back(s[i]);
            mp[t[i]]++;
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
    
    return 0;
}