#include <iostream>
#include <math.h>
using namespace std;
int main() {
int n;
cin>>n;
int a[n];

for(int i=0;i<n;i++)
{
    cin>>a[i];
}

int gap=n/2;
for(int i=gap;i>0;i/=2)
{
    for(int j=0;j<n;j++)
    {

            int k=j;
            while(k>=0&&(k+i)<n&&a[k]>a[k+i])
            {
                if(k+i>=n)
                {
                    break;
                }
                int t=a[k];
                a[k]=a[k+i];
                a[k+i]=t;
                k--;

        }

    }

}
for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}