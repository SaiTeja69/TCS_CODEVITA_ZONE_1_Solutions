#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll;
ll inf=1000000000000000000,mod=1000000007,BS,k;
#define en printf("\n");
int main(){
        string a,b;
        getline(cin,a);int res=0,p,c,f,a_len,b_len;
        a_len=a.length();
        for(int i=0;i<a_len;i++){
            if(a[i]==' ')continue;
            if(isdigit(a[i])){
                res=res*10+a[i]-'0';
            }
            else{
                if(a[i]=='P')
                p=res;
                else if(a[i]=='C')
                c=res;
                else
                f=res;
                res=0;
            }
        }
        getline(cin,b);int pp,cc,ff;
        vector<pair<int,pair<int,int>>>ans;res=0;
        int mi=INT_MAX,sump=0,sumc=0,sumf=0;
        b_len=b.length();
        for(int i=0;i<b_len;i++){
            if(b[i]==' ')continue;
            if(b[i]=='|'){
                ans.push_back({pp,{cc,ff}});
                pp=0;ff=0;cc=0;
            }
            if(isdigit(b[i])){
                res=res*10+b[i]-'0';
            }
            else{
                if(b[i]=='P')
                pp=res,sump+=pp;
                else if(b[i]=='C')
                cc=res,sumc+=cc;
                else
                ff=res,sumf+=ff;
                res=0;
            }
        }ans.push_back({pp,{cc,ff}});
        if(sump)
        mi=min(mi,p/sump);
        if(sumc)
        mi=min(mi,c/sumc);
        if(sumf)
        mi=min(mi,f/sumf);
        if(mi==INT_MAX)mi=0;
        int nn=ans.size();
        pair<int,pair<int,int>>lef,ma={0,{0,0}},curr;
        // cout<<p<<" "<<c<<" "<<f;
        lef={p-mi*sump,{c-mi*sumc,f-mi*sumf}};
        // cout<<lef.first<<" "<<lef.second.first<<" "<<lef.second.second;
        for(int i=0;i<(1<<nn);i++){
            curr={0,{0,0}};
            for(int j=0;j<nn;j++){
                if(i&(1<<j))
                {
                    curr.first+=ans[j].first;
                    curr.second.first+=ans[j].second.first;
                    curr.second.second+=ans[j].second.second;
                }
            }
            if(curr.first<=lef.first&&curr.second.first<=lef.second.first&&curr.second.second<=lef.second.second)
            ma=max(ma,curr);
        }
        cout<<p-sump*mi-ma.first<<" "<<c-sumc*mi-ma.second.first<<" "<<f-sumf*mi-ma.second.second<<endl;
    return 0;
}

