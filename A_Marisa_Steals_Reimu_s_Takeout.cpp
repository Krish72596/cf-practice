#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n);
        vector<int>has(3,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==0) has[0]++;
            else if(a[i]==2) has[2]++;
            else has[1]++;
        }
        int mini=min(has[1],has[2]);
        cout<<has[0]+mini+(has[1]-mini)/3 +(has[2]-mini)/3<<endl;
    }
}