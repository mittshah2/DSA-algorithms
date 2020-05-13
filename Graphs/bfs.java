package com.mitt;

import java.sql.Array;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

  static  int sum(int[] a,int n)
    {
        int sum=0;
        for(int i=1;i<n;i++)
        {
            sum+=a[i];
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("enter no. of vertices");
        int n=s.nextInt();
        n++;
        int[][] a=new int[n][n];
        Queue<Integer> queue=new LinkedList<>();


        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                a[i][j]=s.nextInt();
            }
        }

        int[] vis=new int[n];
        queue.add(1);
        vis[1]=1;
        System.out.print("1 ");
            while(!queue.isEmpty())
            {
               int i=queue.remove();
                for (int j=1;j<n;j++)
                {
                    if(a[i][j]==1)
                    {
                        if(vis[j]!=1)
                        {
                            System.out.print(j+" ");
                        }
                        vis[j]=1;
                        if(sum(vis,n)==n-1)
                            return;
                        queue.add(j);
                    }
                }

            }
        }
    }

