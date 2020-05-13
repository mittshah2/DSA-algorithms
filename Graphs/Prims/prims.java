package com.mitt;

import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    static int findMin(int[] vis,int n,int e,ArrayList<graph> ed)
    {

       for(int i=0;i<ed.size();i++){

           if(ed.get(i).edge==e && vis[ed.get(i).j]==0)
           {
               return ed.get(i).j;
           }
       }

        return -1;
    }

    static ArrayList<Integer> prims(int i,int n,int[][] a,ArrayList<graph> ed)
    {
        ArrayList<Integer> edges=new ArrayList<>();
        PriorityQueue<Integer> pq=new PriorityQueue<>();
        int[] vis=new int[n];
        vis[i]=1;
        for(int j=0;j<n-1;j++)
        {
            System.out.print(i+1+" ");
            vis[i]=1;
            for(int k=0;k<n;k++)
            {
                if(a[i][k]>0 && vis[k]==0)
                {
                    pq.add(a[i][k] );
                }

            }
            int e=pq.remove();
            i=findMin(vis,n,e,ed);
            edges.add(e);
        }
        return edges;
    }

    public static void main(String[] args) {
        int n;
        Scanner s=new Scanner((System.in));
        System.out.println("enter no. of vertices");
        n=s.nextInt();
        int[][] a=new int[n][n];
        ArrayList<graph> ed=new ArrayList<graph>();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=s.nextInt();
                if(a[i][j]>0)
                {
                    ed.add(new graph(i,j,a[i][j]));
                }
            }
        }
        ArrayList<Integer> edge=prims(0,n,a,ed);
        System.out.println();
        for(int j=0;j<edge.size();j++)
        {
            System.out.print(edge.get(j)+" ");
        }


    }
}
