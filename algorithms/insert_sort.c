/******************************************************************
  * File Name     : insert_sort.c
  * Description   : 
  *
  * Copyright (C) 2016 Yangguang Li
  * Mail          : liyggyj@163.com
  * Author        : Yangguang Li
  * Created time  : 2017-01-21 02:50:50 PM
  * Last modified : 2017-01-21 10:57:29 PM
******************************************************************/
#include <math.h>
#include <stdio.h>
static void do_shell_sort(int arr[], int n, int dk)
{
    int i, k, val;
    for (i = 1; i < n; ++i) {
		k = i;
        val = arr[k];
        while (k-dk >= 0 && arr[k-dk] > val) {
            arr[k] = arr[k-dk];
            k -= dk;
        }
        arr[k] = val;
    }
}

void shell_sort(int arr[], int n)
{
    int i;
    int times = (n >> 2) > 1 ? (n >> 2) : 1;
    for (i = 0; i < times; ++i)
        do_shell_sort(arr, n, (int)(pow(2.0, (double)(times-i)))-1);
}


void insert_sort(int arr[], int n)
{
    do_shell_sort(arr, n, 1);
}


