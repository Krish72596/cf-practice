#include <bits/stdc++.h>
using namespace std;
void build(vector<int>&seg,vector<int>&a,int ind,int l,int r,bool isOr){
    if(l==r) {seg[ind]=a[l];return;}
    int mid=(l+r)/2;
    build(seg,a,2*ind+1,l,mid,!isOr);
    build(seg,a,2*ind+2,mid+1,r,!isOr);
    if (isOr)
        seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
    else
        seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
}

void update(vector<int>&seg,vector<int>&a,int node,int ind,int new_val,int l,int r,bool isOr){
    if(l==r) {seg[node]=new_val;return;}
    else{
        int mid=(l+r)/2;
        if(ind<=mid)
            update(seg,a,2*node+1,ind,new_val,l,mid,!isOr);
        else
            update(seg,a,2*node+2,ind,new_val,mid+1,r,!isOr);
        if (isOr)
        seg[node] = seg[2 * node + 1] | seg[2 * node + 2];
    else
        seg[node] = seg[2 * node + 1] ^ seg[2 * node + 2];
    }
}
int main(){
    int n,m;cin>>n>>m;
    int s=1<<n;
    vector<int>a(s);
    vector<int>seg(4*s);
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
    bool rootOr = (n % 2 == 1);
    build(seg,a,0,0,s-1,rootOr);
    while(m--){
        int p,q;cin>>p>>q;
        p--;
        update(seg,a,0,p,q,0,s-1,rootOr);
        cout<<seg[0]<<endl;

    }
}