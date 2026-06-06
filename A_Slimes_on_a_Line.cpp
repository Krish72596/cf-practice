#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
        cin >> n;

        vector<int> a(n);

        int mn = 1e9, mx = -1e9;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }

        cout << (mx - mn + 1) / 2 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}