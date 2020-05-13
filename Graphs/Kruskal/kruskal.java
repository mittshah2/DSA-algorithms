package com.mitt;

import java.util.*;

public class Main {

    static vertex findMin(int[][] a,int n)
    {
        int min=1000;
        int r=0,c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]!=0&&a[i][j]<min)
                {
                    min=a[i][j];
                    r=i;
                    c=j;
                }
            }
        }
        return new vertex(r,c,min);
    }


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
        ArrayList<vertex> tree=new ArrayList<>();
        int[] comp=new int[n];
        int[][] b=a;
        for(int i=0;i<n;i++)
        {
            comp[i]=i;
        }
        //0 8 15 13 0 0 0 8 0 0 9 5 0 0 15 0 0 0 0 3 0 13 9 12 0 2 0 5 0 5 0 2 0 0 0 0 0 3 0 0 0 1 0 0 0 5 0 1 0
        while(tree.size()<n-1)
        {
            vertex min=findMin(b,n);
          while(comp[min.i]==comp[min.j])
          {
              b[min.i][min.j]=0;
              min=findMin(b,n);
          }
            tree.add(new vertex(min.i,min.j,min.edge));
            System.out.print(tree.get(tree.size()-1).edge+" ");
          for(int i=0;i<n;i++)
          {
              if(comp[i]==comp[min.j])
              {
                  comp[i]=comp[min.i];
              }
          }


        }


    }
}
