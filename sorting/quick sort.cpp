#include <iostream>
using namespace std;

void quickSort(int a[],int l,int r)
{
    if(l>r)
    {
        return;
    }
    int p=a[l];
    int y=l;

    for(int g=y+1;g<=r;g++)
    {
        if(a[g]<p)
        {
            int t=a[y+1];
            a[y+1]=a[g];
            a[g]=t;
            y++;
        }
    }

    int t=a[y];
    a[y]=a[l];
    a[l]=t;

    quickSort(a,l,y-1);
    quickSort(a,y+1,r);
}

int main() {
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
    cin>>a[i];
}

quickSort(a,0,n-1);

for(int i=0;i<n;i++)
{
    cout<<a[i]<<" ";
}


    return 0;
}