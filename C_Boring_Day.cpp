#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,l,r;cin>>n>>l>>r;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    long long sum=0;
    int left=0,right=0;
    int count=0;
    for(int right=0;right<n;right++){
        sum+=a[right];
        while(left<=right && sum>r){
            sum-=a[left];
            left++;
        }
        if(sum>=l && sum<=r){
            sum=0;
            count++;
            left=right+1;
        }
        
    }
    cout<<count<<endl;
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