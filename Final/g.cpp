#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 105;
int n, a[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n-1; i++) cin >> a[i];

        int sum = 0;
        for (int i = 0; i < n-1; i++) sum += a[i];

        cout << -sum << endl;
    }
    

    return 0;
}