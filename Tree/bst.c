#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;

struct node* createNode()
{
    struct node *np;
    np=(struct node*)malloc(sizeof(struct node));
    return np;
}

void insert()
{
    int n;
    printf("enter data:");
    scanf("%d",&n);
    struct node *np=createNode();
    np->data=n;
    np->left=NULL;
    np->right=NULL;

    if(root==NULL)
        root=np;
    else
    {
        struct node *t=root;

        while(t->data>np->data&&t->left!=NULL)
                {
                    t=t->left;
                }

        while(t->data<np->data&&t->right!=NULL)
                {
                   t=t->right;
                }

            if(t->data>np->data)
            {
                if(t->left!=NULL)
                {
                    while(t->left!=NULL)
                        t=t->left;
                         t->left=np;
                }
                else
                 t->left=np;
            }

            else
            {

                if(t->right!=NULL)
                {
                    while(t->right!=NULL)
                        t=t->right;
                         t->right=np;
                }
                else
                t->right=np;
            }



    }
}

void disp(struct node *t)
{
    if(t==NULL)
        return;
   disp(t->left);
   printf("%d ",t->data);
   disp(t->right);
}

void del(int n)
{
    struct node *t=root;
    struct node *t1,*t2;
    while(t->data!=n)
    {
        if(n>t->data)
        {
            if(t->right->data==n)
              {
                  t1=t;
              }
            t=t->right;
        }
        else
        {
            if(t->left->data==n)
                {
                    t1=t;
                }
                 t=t->left;
        }

    }


      if(t->left!=NULL||t->right!=NULL)
    {
        if(t->right!=NULL&&t->left==NULL)
        {
            t2=t->right;
            t->data=t2->data;
            t->right=NULL;
        }
        else if(t->left!=NULL&&t->right==NULL)
        {
            t2=t->left;
            t->data=t2->data;
            t->left=NULL;
        }
        else if(t->left!=NULL&&t->right!=NULL)
        {

        t2=t->left;
        if(t2->right==NULL)
        {
            t1=t;
        }
        while(t2->right!=NULL)
        {
            if(t2->right->right==NULL)
            {
                t1=t2;
            }
            t2=t2->right;
        }


        t->data=t2->data;
        if(t1->right==t2)
        {
            t1->right=NULL;
        }
        else
        t1->left=NULL;
        }

    }

else if(t->left==NULL&&t->right==NULL)
    {

        if(t1->left!=NULL&&t1->left->data==n)
        {
           t1->left=NULL;

        }
        else if(t1->right!=NULL&&t1->right->data==n)
        {
            t1->right=NULL;

    }

    }
}

int main()
{
    int c=1,n,n1;
    while(c==1)
    {
        printf("1.insert\n2.delete\n3.display\nenter your choice:");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert();
            break;
        case 2:
            printf("enter element to be deleted:");
            scanf("%d",&n1);
            del(n1);
           break;
        case 3:
            disp(root);
            break;
        default:
            printf("enter valid choice");
        }
        printf("\ndo you want to continue:");
        scanf("%d",&c);
    }

}
