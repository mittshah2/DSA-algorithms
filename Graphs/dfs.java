package com.mitt;

import java.util.Scanner;

public class Main {

    static void dfs(int i,int[][] a,int[] vis,int[] par,int n)
    {
        vis[i]=1;
        for(int j=1;j<n;j++)
        {
            if(vis[j]==0)
            {
                System.out.print(j+" ");
                par[j]=i;
                dfs(j,a,vis,par,n);
            }
        }

    }
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("enter no. of vertices");
        int n=s.nextInt();
        n++;
        int[][] a=new int[n][n];
        for(int j=1;j<n;j++)
        {
            for(int k=1;k<n;k++)
            {
                a[j][k]=s.nextInt();
            }
        }      int[] vis=new int[n];
        int[] par=new int[n];
        System.out.print(4+" ");
        dfs(4,a,vis,par,n);

    }
}
