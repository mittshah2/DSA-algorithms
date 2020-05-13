#include <iostream>
using namespace std;
int main() {

    int n;
    cin>>n;
    int ori[n];
    for(int i=0;i<n;i++)
    {
        cin>>ori[i];
    }
    int out[n+1];
    int count[10];

    for(int i=0;i<10;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        count[ori[i]]++;
    }

    for(int i=1;i<10;i++)
    {
     count[i]+=count[i-1];
    }

    for(int i=0;i<(n);i++)
    {
        out[count[ori[i]]]=ori[i];
        count[ori[i]]--;

    }

    for(int i=1;i<n+1;i++)
    {
        cout<<out[i]<<" ";
    }

    return 0;
}