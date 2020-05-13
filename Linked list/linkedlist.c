#include<stdio.h>

struct node{
    int value;
    struct node *next;
};
struct node *first=NULL;

//struct node *temp1=NULL;


void insertLast(struct node *new1,struct node *temp){
    //struct node *new1=NULL;
    struct node *bet=(struct node*)malloc(sizeof(struct node));
    bet=first;
    new1=(struct node*)malloc(sizeof(struct node));

    //printf("%d %u",temp->value,temp->next);
    printf("what do you want to insert \n");
    int newValue;
    scanf("%d",&newValue);
    new1->value=newValue;
    new1->next=NULL;
    while(bet->next!=NULL)
    {
            bet=bet->next;
    }
    bet->next=new1;
    printf("value %d address of previous %u new address %u\n",newValue,bet->next,new1->next);

}

void insertAfter(struct node *new1,struct node *temp){
    //struct node *new1=NULL;
    struct node *bet=(struct node*)malloc(sizeof(struct node));
    bet=first;
    new1=(struct node*)malloc(sizeof(struct node));
    printf("what do you want to insert \n");
    int newValue;
    scanf("%d",&newValue);
    printf("After what number you want to insert?\n");
    int num;
    scanf("%d",&num);
    while(bet->value!=num){
            bet=bet->next;
    }
    new1->value=newValue;struct node *bet=(struct node*)malloc(sizeof(struct node));
    new1->next=bet->next;
    bet->next=new1;
    printf("value %d address of previous %u new address %u\n",newValue,bet->next,new1->next);

}
void insertFirst(struct node *new1,struct node *temp){
    //struct node *new1=NULL;
    new1=(struct node*)malloc(sizeof(struct node));
    printf("what do you want to insert \n");
    int newValue;
    scanf("%d",&newValue);
    new1->value=newValue;
    new1->next=first;
    first=new1->next;
    first=new1;
    printf("value %d address of previous %u new address %u\n",newValue,temp->next,new1->next);

}

void deleteLast(struct node *new1,struct node *temp){
    struct node *bet=(struct node*)malloc(sizeof(struct node));
    bet=first;
    while(bet->next->next!=NULL){
           bet=bet->next;
    }
    bet->next=NULL;
    free(bet->next);

}

void deleteBefore(struct node *new1,struct node *temp){
    //struct node *new1=NULL;
    struct node *bet=(struct node*)malloc(sizeof(struct node));
    bet=first;
    struct node *bet2=(struct node*)malloc(sizeof(struct node));
    printf("After what number you want to delete?\n");
    int num;
    scanf("%d",&num);
    while(bet->next->next->value!=num){
            bet=bet->next;
    }
    bet2=bet->next;
    bet->next=bet->next->next;
    free(bet2);
    //bet->next=bet->next->next;
}
void deleteFirst(struct node *new1,struct node *temp){
    //struct node *new1=NULL;
    struct node *bet=(struct node*)malloc(sizeof(struct node));
    bet=first;
    first=bet->next;
    free(bet);
}

int display(struct node *first)
{
  struct node *temp=first;
  if(temp==NULL)
  {
      printf("EMPTY\n");
      return NULL;
  }
  while(temp->next!=NULL)
  {
   //   printf("%d\t",temp->data);
    printf("temp data->%d and temp->next=%u at %u\n",temp->value,temp->next,temp);
      temp=temp->next;
  }
    //    printf("%d\t",temp->data);
  printf("temp data->%d and temp->next=%u at %u\n",temp->value,temp->next,temp);
}
int main()
{
    int c,s;
    struct node *new1=NULL;
    first=(struct node*)malloc(sizeof(struct node));
    struct node *temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=first;

    printf("what do you want to insert \n");
    int newValue;
    scanf("%d",&newValue);
    first->value=newValue;
    first->next=0;
    printf("value %d address %u \n",newValue,first->next);


    printf("what do you want 1.insert 2.delete 3.display 4.exit\n");
    scanf("%d", &c);
    while(c!=4){
    switch(c){
        case 1:{
            printf("what do you want 1.insertLast 2.insertBetween 3.insertFirst\n");
            scanf("%d",&s);
            switch(s)
            {
            case 1:
                {
                    insertLast(new1,temp);
                    break;
                }
            case 2:
                {
                    insertAfter(new1,temp);
                    break;
                }
            case 3:
                {
                    insertFirst(new1,temp);
                    break;
                }
            }
            break;
        }
        case 2:
            {
            printf("what do you want 1.deleteLast 2.deleteBetween 3.deleteFirst\n");
            scanf("%d",&s);
            switch(s)
            {
            case 1:
                {
                    deleteLast(new1,temp);
                    break;
                }
            case 2:
                {
                    deleteBefore(new1,temp);
                    break;
                }
            case 3:
                {
                    deleteFirst(new1,temp);
                    break;
                }
            }
            break;
        }
        case 3:
            {
                    display(first);
            }
    }
        printf("what do you want 1.insert 2.delete 3.display 4.exit \n");
        scanf("%d", &c);

    }
}



