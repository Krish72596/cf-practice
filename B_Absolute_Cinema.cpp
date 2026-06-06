#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
        cin >> n;

        vector<long long> a(n), b(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        long long sum = 0;
        long long best = 0;

        for (int i = 0; i < n; i++) {
            sum += max(a[i], b[i]);
            best = max(best, min(a[i], b[i]));
        }

        cout << sum + best << '\n';
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