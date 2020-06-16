#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
const int maxn=110;
int n,m,t,is,cnt,ans;
struct xx{
    int l,r;
}xx[maxn];
bool cmp(struct xx a,struct xx b){
    if(a.r==b.r)return a.l<b.l;
    return a.r<b.r;
}
int main(){
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(2);
    while(cin>>n){
        if(!n)return 0;
        int ans=0,cnt=0;
        for(int i=1;i<=n;i++)cin>>xx[i].l>>xx[i].r;
        sort(xx+1,xx+1+n,cmp);
        for(int i=1;i<=n;i++){
            if(cnt<=xx[i].l){
                ++ans;
                cnt=xx[i].r;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
    //good job!
}
