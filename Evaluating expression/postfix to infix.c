#include<stdio.h>
#include<string.h>
int top=-1;
char ns[50][50];

void push(char s,int n){
    top++;
    ns[top][0]=s;
    ns[top][1]='\0';
}
void pop(char s,int n){
    top--;
    char brac1[100];
    char brac2[2];
    char str[2];
    str[0]=s;
    str[1]='\0';
    brac1[0]='(';
    brac1[1]='\0';
    brac2[0]=')';
    brac2[1]='\0';
    strcat(brac1,ns[top]);
    strcat(brac1,str);
    strcat(brac1,ns[top+1]);
    strcat(brac1,brac2);
    strcpy(ns[top],brac1);
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
                (pop(s[i],n));
                break;
            }
            case '-':{
                (pop(s[i],n));
                break;
            }
            case '*':{
                (pop(s[i],n));
                break;
            }
            case '/':{
                (pop(s[i],n));
                break;
            }
            default:{
                (push(s[i],n));
                break;
            }
        }
    }
    printf("%s",ns[0]);
}
