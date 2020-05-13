#include<stdio.h>
#include<string.h>

int push(char c);
int pop();
int prior(char c);

int top=-1;
char stack[30];

int main()
{
    int i;
    char s[50],x,c;
    scanf("%s",s);
    int n=strlen(s);
    for(i=0;i<n;i++){
            c=s[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
            printf("%c",c);
        }
        else if(c=='('){
            push(c);
        }
        else if(c==')'){
            while((x=pop())!='('){
                    printf("%c",x);
                  }
        }
        else{
            while(prior(stack[top])>=prior(c)){
                printf("%c",pop());
            }
            push(c);
        }
    }
    while(top!=-1){
        printf("%c",pop());
    }
}
int push(char c)
{
    top=top+1;
    stack[top]=c;
}
int pop()
{
    top=top-1;
    return (stack[top+1]);
}
int prior(char c)
{
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
