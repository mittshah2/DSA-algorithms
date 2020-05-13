#include<stdio.h>
#include<string.h>
int top=-1;
char stack[50];

void push(char c)
{
    top++;
    stack[top]=c;
}
int pop()
{
    top--;
    return stack[top+1];
}
int priority(char c){
    if(c=='/'||c=='*'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return 0;
    }

}

int main()
{
    int i,j;
    char s[50],x,ch;
    scanf("%s",s);
    int n=strlen(s);
    for(i=0;i<n;i++){
            ch=s[i];
        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')){
            printf("%c",ch);
        }
        else if(ch=='('){
            push(ch);
        }else if(ch==')'){
            while((x=pop())!='('){
                    printf("%c",x);
                  }

        }else{

            while(priority(stack[top])>=priority(ch)){
                printf("%c",pop());
            }
            push(ch);
        }

    }
    while(top!=-1){
        printf("%c",pop());
    }
}
