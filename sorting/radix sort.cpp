#include <iostream>
using namespace std;


int main() {
    int n;
    cin>>n;
    int a[n],b[n];
    int max=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        if(a[i]>max)
        {
            max=a[i];
        }
    }

    int count[10];
    int out[n];

    for(int i=1;(max/i)>0;i*=10)
    {
        for(int j=0;j<=9;j++)
        {
            count[j]=0;
        }
        for(int j=0;j<n;j++)
        {
            b[j]/=i;
        }
        for(int j=0;j<n;j++)
        {
            count[b[j]%10]++;
        }

        for(int j=1;j<10;j++)
        {
            count[j]+=count[j-1];
        }

        for(int j=n-1;j>=0;j--)
        {
            out[count[b[j]%10]-1]=a[j];
            count[b[j]%10]--;
        }
        for(int j=0;j<n;j++)
        {
            a[j]=out[j];
            b[j]=out[j];
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}