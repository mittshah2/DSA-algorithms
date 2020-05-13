#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int n;
    node *next;
}*top=NULL;

struct node* createNode()
{
    node *np;
    np=(struct node*)malloc(sizeof(struct node));
    return np;
}

void insertFirst()
{
    printf("enter data:");
    int a;
   scanf("%d",&a);
   struct node *np=createNode();
    np->n=a;
    np->next=np;
    if(top==NULL)
        top=np;
    else
      {
         struct node *temp=top;
          while(temp->next!=top)
            temp=temp->next;
          temp->next=np;
          np->next=top;
          top=np;
          printf("%d",top->n);
      }
}
void insertLast()
{
  printf("enter data:");
    int a;
    scanf("%d",&a);
   struct node *np=createNode();
    np->n=a;
    np->next=np;
    if(top==NULL)
        top=np;
    else
      {
         struct node *temp=top;
          while(temp->next!=top)
            temp=temp->next;
          temp->next=np;
          np->next=top;
      }
}

void insertAfter(int b)
{
   printf("enter data:");
    int a;
    scanf("%d",&a);
   struct node *np=createNode();
    np->n=a;
    np->next=np;
    if(top==NULL||top->next==top)
        printf("not possible");
    else
    {
        struct node *temp=top;
        while(temp->n!=b)
            temp=temp->next;
        np->next=temp->next;
        temp->next=np;
    }
}

void deleteFirst()
{
    if (top==NULL)
        printf("underflow");
    else
    {
        struct node *temp=top;
        while(temp->next!=top)
            temp=temp->next;
        temp->next=top->next;
        temp=top;
        top=top->next;
        temp->next=NULL;
        free(temp);
        printf("%d",top->n);
    }
}

void deleteLast()
{
    if (top==NULL)
        printf("underflow");
        else
        {
            struct node *temp=top;
            while(temp->next->next!=top)
                temp=temp->next;
            free(temp->next);
            temp->next=top;
        }
}

void deleteAfter(int b)
{
     if (top==NULL||top->next==top)
        printf("not possible");
        else
        {
             struct node *temp=top;
             while(temp->next->n!=b)
                temp=temp->next;
                free(temp->next);
             temp->next=temp->next->next;

        }
}
void disp()
{
   struct node *temp;
   temp=top;


    while(temp->next!=top)
    {
        printf("%d",temp->n);
        temp=temp->next;
    }
 printf("%d",temp->n);
}


int main()
{
    int c;
do{
    printf("1.insert first\n2.insert last\n3.insert in between\n4.delete first\n5.delete in between\n6.delete last\n7.display\nenter your choice:");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        insertFirst();
        break;
    case 2:
        insertLast();
        break;
   case 3:
       printf("enter after which element:");
       int b;
       scanf("%d",&b);
        insertAfter(b);
        break;
   case 4:
        deleteFirst();
        break;
    case 5:
        printf("enter after which element:");
        scanf("%d",&b);
        deleteAfter(b);
        break;
    case 6:
        deleteLast();
        break;
    case 7:
        disp();
        break;
    }
    printf("do you want to continue:");
    scanf("%d",&c);
}while (c==1);
return 0;
}
