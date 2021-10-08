package com.company;

import java.util.Arrays;

public class Cyclicsort {
    public static void main(String[] args){
        int[] a={3,5,2,1,4};
        Cyclic_Sort(a);
        System.out.println(Arrays.toString(a));
    }
    static void Cyclic_Sort(int[]a){
        int i = 0;
        while (i < a.length) {
            int correct = a[i] - 1;
            if (a[i] != a[correct]) {
                swap(a, i, correct);
            } else {
                i++;
            }
        }

    }
    static void swap(int[] arr,int i,int correct){
        int temp;
        temp=arr[i];
        arr[i]=arr[correct];
        arr[correct]=temp;
    }
}
