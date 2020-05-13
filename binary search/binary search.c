#include<stdio.h>
void bsearch(int a[],int n,int element)
{
    int low,mid,high;
    low=0;
	high=n-1;
	int t;

	mid=(low+high)/2;
	while(low<=high)
	{
	    mid=(low+high)/2;
        if(a[mid]==element)
		{
		    t=1;
			printf("found at  location %d \n",mid+1);
			break;
		}
		else if(a[mid]>element)
		{
			high=mid-1;
		}
		else if(a[mid]<element)
		{
			low=mid+1;
		}

	}
	if(t!=1)
		printf("not found \n");
	return 0;
}

int main()
{
	int n,element;
	printf("enter the number of element  :");
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
	{
	    printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}

	printf("enter the search element : ");
	scanf("%d",&element);
    bsearch(a,n,element);
}
