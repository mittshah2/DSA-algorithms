#include<stdio.h>
#include<string.h>

int top=-1;
int stack[50];

int push(char c)
{
    top++;
    stack[top]=c;
}
int pop(char c)
{
    top--;
    int n;
    switch(c){
        case '+':{
            n=(stack[top]-48)+(stack[top+1]-48);
            break;
        }
        case '-':{
            n=(stack[top]-48)-(stack[top+1]-48);
            break;
        }
        case '*':{
            n=(stack[top]-48)*(stack[top+1]-48);
            break;
        }
        case '/':{
            n=(stack[top]-48)/(stack[top+1]-48);
            break;
        }

    }
    stack[top]=n+48;
}

int main()
{
    char s[50];
    gets(s);
    int i;
    for(i=0;i<strlen(s);i++){
        switch(s[i]){
            case '+':{
                pop(s[i]);
                break;
            }
            case '-':{
                pop(s[i]);
                break;
            }
            case '*':{
                pop(s[i]);
                break;
            }
            case '/':{
                pop(s[i]);
                break;
            }
            default:{
                push(s[i]);
                break;
            }
        }
    }
    printf("%d",stack[0]-48);
}
