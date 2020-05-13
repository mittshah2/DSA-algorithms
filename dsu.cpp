#include<bits/stdc++.h>
using namespace std;

class unionFind
{
private:
    vector<int> rank,p;
    int noc;
public:
    unionFind(int n)
    {
        rank.assign(n,0);
        p.assign(n,0);
        noc=n;
        for(int i=0;i<n;i++)
        {
            p[i]=i;
        }
    }
    int find(int i)
    {
        return (p[i] == i) ? i : (p[i] = find(p[i]));
    }
    bool isSameSet(int i,int j)
    {
        return find(i)==find(j);
    }
    void unionSet(int i,int j)
    {
        if(!isSameSet(i,j))
        {
            int x=find(i);
            int y=find(j);
            noc--;
            if(rank[x]>rank[y])
            {
                p[y]=x;
            } else{
                p[x]=y;
            }
            if(rank[x]==rank[y])
            {
                rank[y]++;
            }
        }
    }
    int getNoc()
    {
        return noc;
    }

};

int main() {

    int n;
    cin>>n;
    int a[n][2];
    unionFind dsu(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][0]==a[j][0]||a[i][1]==a[j][1])
            {
                dsu.unionSet(i,j);
            }
        }
    }
    cout<<dsu.getNoc()-1;

    return 0;
}