package com.mitt;

import java.util.Scanner;

public class Main {
public static int f(char[] s,char[] t,int sl,int tl)
{

    if(sl==0||tl==0)
        return 0;
    else if(s[sl-1]==t[tl-1])
        return f(s,t,sl-1,tl-1)+1;
    else
        return Math.max(f(s,t,sl,tl-1),f(s,t,sl-1,tl));
}

    public static void main(String[] args) {
    String s,t;
        System.out.println("enter s");
        Scanner s1=new Scanner(System.in);
        s=s1.nextLine();
        System.out.println("enter t");
        t=s1.nextLine();
        char[] x=s.toCharArray();
        char[] y=t.toCharArray();
       int a= f(x,y,s.length(),t.length());
        System.out.println(a);

    }
}
