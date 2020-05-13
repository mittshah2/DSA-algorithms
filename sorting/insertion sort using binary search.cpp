#include <iostream>
using namespace std;

int upperBound(int arr[],int l,int r,int d)
{
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==d)
        {
            ans=mid;
            l=mid+1;
        }
        else if(arr[mid]>d)
        {
            r=mid-1;
        }
        else
            l=mid+1;
    }
    if(ans==-1)
    {

        return l;
    }
    return ans;
}

int main() {

    int arr[]={7,6,5,4,3,2,1};

    for(int i=1;i<7;i++)
    {
        int j=i-1;
        while(arr[i]<arr[j])
        {
            int a=upperBound(arr,0,j,arr[i]);
            int t=arr[a];
            arr[a]=arr[i];
            arr[i]=t;

        }

    }
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}