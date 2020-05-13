package com.mitt;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	Scanner s=new Scanner(System.in);
int [] arr=new int[6];
for(int i=0;i<5;i++)
{
    arr[i]=s.nextInt();
}
	for(int i=0;i<5;i++)
    {
        int j=i;
        while(j>0&&arr[j-1]>arr[j])
        {
            int t=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=t;
            j--;
        }

    }
        for(int i=0;i<5;i++)
        {
            System.out.println(arr[i]);
        }

    }
}
