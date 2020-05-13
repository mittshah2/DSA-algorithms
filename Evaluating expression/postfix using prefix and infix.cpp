// C++ program to print postorder traversal from preorder and inorder traversals 
#include <iostream>
using namespace std;

int search(int arr[], int x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void printPreOrder(int in[],int pre[],int n)
{
    int root=search(in,pre[0],n);


    if(root!=0)
    {
        printPreOrder(in,pre+1,root);
    }
    if(root!=n-1)
    {
        printPreOrder(in+root+1,pre+root+1,n-root-1);
    }
    cout<<pre[0]<<" ";

}
int main()
{
    int pre[] = { 5,1,3,11,6,8,4,2,7 };
    int in[] = {6,1,5,11,3,4,8,7,2};
   int n=9;
    printPreOrder(in, pre, n);
    return 0;
} 
