#include<stdio.h>

int arr[5][2];
int f=-1,r=-1;

void insert()
{
    int i,j,temp,tempa;
    if(r-f==4){
        printf("queue overflow\n");
        return;
    }
    else if(f==-1&&r==-1){
        f=0;
        r=0;
    }
    else{
        r++;
    }
    printf("enter the no\n");
    scanf("%d",&arr[r][0]);
    printf("enter the prior no\n");
    scanf("%d",&arr[r][1]);
    if(f>=0&&r>0){
            for(i=f;i<=r;i++){
                for(j=i+1;j<=r;j++){
                    if(arr[j][1]>arr[i][1]){
                        tempa=arr[i][0];
                        arr[i][0]=arr[j][0];
                        arr[j][0]=tempa;
                        tempa=arr[i][1];
                        arr[i][1]=arr[j][1];
                        arr[j][1]=tempa;

                    }
                }
            }

    }
    printf("your priority queue is now \n");
    for(i=f;i<=r;i++){
        printf("%d ",arr[i][0]);
    }
}
int del()
{
    int temp;
    if(r-f==-1||(r==-1&&f==-1)){
        printf("queue underflow\n");
        return;
    }
    else if(r==4&&f==4){
        temp=arr[f][0];
        r=-1;
        f=-1;
        return temp;
    }
    else{
        temp=arr[f][0];
        f++;
        return temp;
    }
}

int main()
{
    int i,c,x;
    printf("what do you want 1.enter 2.delete 3.exit\n");
    scanf("%d",&c);
    while(c!=3){
        if(c==1){
            insert();
        }
        else if(c==2){
            x=del();
            printf("deleted element is %d\n",x);
        }
        else{
            break;
        }
        printf("what do you want 1.enter 2.delete 3.exit\n");
        scanf("%d",&c);
    }

    printf("sorted priority queue is\n");
    for(i=f;i<=r;i++){
        printf("%d ",arr[i][0]);
    }

}
