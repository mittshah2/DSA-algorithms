#include<stdio.h>


int hanoi(int n,char a,char b,char c)
{

    if(n==1){
        printf("the disk %d moved from %c to %c \n",n,a,b);
    }
    else if(n==0){
        return 0;
    }
    else{
        hanoi(n-1,a,c,b);
        printf("the disk %d moved from %c to %c \n",n,a,b);
        hanoi(n-1,c,b,a);
    }
}

int main()
{
    char a='a';
    char b='b';
    char c='c';
    int n;
    scanf("%d",&n);
    hanoi(n,a,b,c);
}
