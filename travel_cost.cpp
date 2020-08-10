#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll;
ll inf=1000000000000000000,mod=1000000007,BS,k;
#define en printf("\n");
int main(){
        ll n;cin>>n;
        ll arr[n],dp[n];
        for(ll i=0;i<n;i++)
        cin>>arr[i];ll m;cin>>m;
        if(arr[n-1]==-1){
        cout<<"-1";return 0;}
        else{
            for(ll i=0;i<n;i++)dp[i]=inf;
            dp[1]=arr[1];dp[0]=0;
            for(ll i=2;i<n;i++){
                if(arr[i]==-1)continue;
                for(ll j=0;j<=m+1;j++){
                    if(i-j>=0&&arr[i-j]!=-1&&dp[i-j]!=inf)
                    dp[i]=min(dp[i],dp[i-j]+arr[i]);
                }
            }
            if(dp[n-1]==inf)
            cout<<"-1";
            else
            cout<<dp[n-1]+arr[0];
        }
    return 0;
}