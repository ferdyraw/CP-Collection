#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    
    while (T--)
    {
        int n,p;
        cin >> n >> p;
        vector<pii> a(n);
        for (auto & i :a ) cin >> i.first;
        for (auto & i :a ) cin >> i.second;
        sort(a.begin(), a.end(), [&] (pii a1, pii a2) {
            return a1.second < a2.second;
        });

        // for (int i= 0; i < n; i++)
        // {
        //     cout << a[i].first << " " << a[i].second << endl;
        // }

        if (p <= a[0].second) {
            cout << p * n << endl;
        } else {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (a[i].second >= p) {
                    break;
                } else {
                    cnt++;
                }
            }
            //cout << cnt << endl;
            int warga = n - 1;
            int harga = p;
    
            for (int i = 0; i < cnt; i++) {
                warga -= a[i].first;
                harga += (a[i].second * a[i].first);
                // cout << harga << endl;

                if (warga == 0) {
                    break;
                } else if (warga < 0) {
                    int lebih = -warga;
                    harga -= (a[i].second * lebih); 
                    break;
                }   
            }

            if (warga > 0) {
                harga += (p * warga);
            }
            
            cout << harga << endl;
        }
    }
    

    return 0;
}