#include<stdio.h>

int r=-1,f=-1;
int q[5];

void insert();
int del();

void insert(){
    int ele;
    printf("enter the number to be insert");
    scanf("%d",&ele);
    if(r==-1&&f==-1){
        f=0;
        r=0;
        q[r]=ele;
    }
    else if(f>0 && r==4){
        r=0;
        q[r]=ele;
    }
    else if(f==r+1||(f==0 && r==4)){
        printf("queue overflow \n");
        return 0;
    }
    else{
        r=r+1;
        q[r]=ele;
    }

}
int del(){
    int temp;
    if(r==-1&&f==-1){
        printf("queue underflow \n");
    }
    else if(r==f){
        temp=q[f];
        r=-1;
        f=-1;
        return temp;
    }
    else if(f==4&&r<f){
        temp=q[f];
        f=0;
        return temp;
    }
    else{
        temp = q[f];
        f=f+1;
        return temp;
    }

}

int main()
{
    int ele[5];
    int i,num,c;
    printf("what do you want 1.insert 2.delete 3.end \n");
    scanf("%d",&c);
    while(c!=3){
        switch(c){
            case 1:{
                insert();
                break;
            }
            case 2:{
                num=del();
                printf("number deleted is %d \n",num);
                break;
            }
        }

        printf("what do you want 1.insert 2.delete 3.end \n");
        scanf("%d",&c);


    }
    if(r<f){
        for(i=f;i<5;i++){
            printf("%d",q[i]);
        }
        for(i=0;i<=r;i++){
            printf("%d",q[i]);
        }
    }
    else{
        for(i=f;i<=r;i++){
            printf("%d ",q[i]);
        }
    }
}
