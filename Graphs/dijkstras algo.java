package com.mitt;

import java.util.Scanner;

public class Main {

    static int findMin(int[][] a,int[] vis,int n)
    {
        int min=10000,mi=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==1)
            {
                for(int j=0;j<n;j++)
                {
                    if(vis[j]==0&&a[i][j]!=0&&a[i][j]<min)
                    {
                        min=a[i][j];
                        mi=j;
                    }
                }
            }
        }

        return mi;
    }

    static void dijkstras(int[][] a,int n,int i)
    {
        int[] vis=new int[n];
        int[] time=new int[n];
        for(int j=0;j<n;j++)
        {
            time[j]=100000;
        }

        vis[i]=1;
        time[i]=0;
        int mi=0;
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<n;j++)
            {
                vis[i]=1;
                mi=findMin(a,vis,n);
                if(a[i][j]!=0)
                {
                    if(time[j]>a[i][j]+time[i])
                    {
                        time[j]=a[i][j]+time[i];
                    }
                }

            }
            i=mi;
        }

        for(int j=0;j<n;j++)
        {
            System.out.print(time[j]+" ");
        }


    }
//0 10 80 0 0 0 0 10 0 6 0 20 0 0 80 6 0 70 0 0 0 0 0 70 0 0 0 0 0 20 0 0 0 50 10 0 0 0 0 50 0 5 0 0 0 0 10 5 0

    public static void main(String[] args) {

        int n;
        Scanner s=new Scanner(System.in);
        System.out.println("enter no. of vertices");
        n=s.nextInt();
        int[][] a=new int[n][n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=s.nextInt();
            }
        }

        dijkstras(a,n,0);

    }
}
