#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> ans;
    bool flipped = false;
    
    // Traverse backwards
    for (int i = n - 1; i >= 0; --i) {
        // Evaluate the *current* value of the element based on the flip state
        int current_val = flipped ? -a[i] : a[i];
        
        if (current_val > 0) {
            ans.push_back(i + 1); // 1-based index
            flipped = !flipped;   // Toggle prefix sign status
        }
    }
    
    // Output the results
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    