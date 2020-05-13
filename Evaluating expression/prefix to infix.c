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
    char brac1[100];
    char brac2[2];
    char nc[2];
    nc[0]=c;
    nc[1]='\0';
    brac1[0]='(';
    brac1[1]='\0';
    brac2[0]=')';
    brac2[1]='\0';
    strcat(brac1,stack[top+1]);
    strcat(brac1,nc);
    strcat(brac1,stack[top]);
    strcat(brac1,brac2);
    strcpy(stack[top],brac1);
}

int main()
{
    char s[500];
    gets(s);
    int i,n,temp;
    n=strlen(s);
    for(i=n-1;i>=0;i--){
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
    return 0;
}
