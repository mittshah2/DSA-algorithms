#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,c;
    cin>>n>>c;
    int w[n],v[n];
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int ans[n+1];
ans[0]=0;
for(int i=0;i<=n;i++)
{
    ans[i]=0;
}
int ma=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        if(w[i-1]<=c)
        {
            int t1=ans[i-1];
            int t2=v[i-1]+ans[i-1];
            if(t2>t1)
            {
                c-=w[i-1];
            }
            ans[i]=max(t1,t2);
            if(ans[i]>ma)
            {
                ma=ans[i];
            }
        }
    }
cout<<ma;
    return 0;
}

