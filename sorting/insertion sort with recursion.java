package com.mitt;

import java.util.Scanner;

public class Main {

    public static int[] f(int[] arr,int i) {
        if (i == arr.length - 1)
            return null;
        else {
            for (int j = i; j < arr.length; j++) {
                int k = j;
                while (k > 0 && arr[k - 1] > arr[k]) {
                    int t = arr[k];
                    arr[k] = arr[k - 1];
                    arr[k - 1] = t;
                    k--;
                }
            }
            f(arr, i + 1);
        }
        return arr;
    }

    public static void main(String[] args) {

        int[] a=new int[7];
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<7;i++)
        {
            a[i]=sc.nextInt();
        }
        a=f(a,0);
        assert a != null;
        for (int value : a) {
            System.out.println(value);
        }
    }
}
