#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

unsigned long long get_diff(unsigned long long a, unsigned long long b) {
    return (a > b) ? (a - b) : (b - a);
}

void solve(){
    string a_str;
    int n,d1,d2;
    cin>>a_str>>n>>d1>>d2;
    ull a_val=stoull(a_str);
    vector<ull>candidates;
    int L=a_str.length();
    if(L>1){
        string s="";
        for(int i=0;i<L-1;i++){
            s+=to_string(d2);
        }
        candidates.push_back(stoull(s));
    }
    if(d1>0){
        string s="";
        for(int i=1;i<L+1;i++) s+=to_string(d1);
        candidates.push_back(stoull(s));
    }else{
        string s=to_string(d2);
        for(int i=0;i<L;i++) s+=to_string(d1);
        candidates.push_back(stoull(s));
    }
    int d[2]={d1,d2};
    string prefix="";
    bool can_match=true;
    for(int i=0;i<L;i++){
        int digit=a_str[i]-'0';

        for(int x:d){
            if(x>digit){
                string cand=prefix+to_string(x);
                for(int j=0;j<L-i-1;j++) cand+=to_string(d1);
                candidates.push_back(stoull(cand));
                break;
            }
        }
        for(int j=1;j>=0;j--){
            int x=d[j];
            if(x<digit){
                string cand=prefix+to_string(x);
                for(int j=0;j<L-i-1;j++) cand+=to_string(d2);
                candidates.push_back(stoull(cand));
                break;
            }
        }
        if(digit!=d1 && digit!=d2){
            can_match=false;
            break;
        }
        prefix+=to_string(digit);
    }
    ull min_diff=-1;
    if(can_match){
        candidates.push_back(a_val);
    }
    for(ull c:candidates){
        ull curr=get_diff(c,a_val);
        min_diff=min(min_diff,curr);
    }
    cout<<min_diff<<"\n";
}






int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}