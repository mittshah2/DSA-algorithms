#include<stdio.h>
#include<string.h>

top=-1;
char stack[50][50];

void push(char c)
{
    top++;
    stack[top][0]=c;
    stack[top][1]='\0';
}
void pop(char c)
{
    top--;
    char nc[100];
    nc[0]=c;
    nc[1]='\0';
    strcat(nc,stack[top]);
    strcat(nc,stack[top+1]);
    strcpy(stack[top],nc);
}

int main()
{
    int i,n;
    char s[50];
    gets(s);
    n=strlen(s);
    for(i=0;i<n;i++){
        switch(s[i]){
            case '+':{
                (pop(s[i]));
                break;
            }
            case '-':{
                (pop(s[i]));
                break;
            }
            case '*':{
                (pop(s[i]));
                break;
            }
            case '/':{
                (pop(s[i]));
                break;
            }
            default:{
                (push(s[i]));
                break;
            }
        }
    }
    printf("%s",stack[0]);
}
