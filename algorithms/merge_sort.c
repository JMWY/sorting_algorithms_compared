/******************************************************************
  * File Name     : msort.c
  * Description   : 
  *
  * Copyright (C) 2016 Yangguang Li
  * Mail          : liyggyj@163.com
  * Author        : Yangguang Li
  * Created time  : 2017-01-19 01:53:03 PM
  * Last modified : 2017-01-20 10:12:49 PM
******************************************************************/
#include <stdlib.h>

static void do_merge_sort(int arr[], int tem[], int left, int right)
{
    if (left >= right) return;
    
    int mid = left + (right - left >> 1);
    do_merge_sort(arr, tem, left, mid);    
    do_merge_sort(arr, tem, mid+1, right);

    int s1 = left,
        s2 = mid+1;
    int i;
    for (i = left; i <= right; ++i) {
        if (s2 > right || (s1 <= mid && arr[s1] <= arr[s2]))
            tem[i] = arr[s1++];
        else
            tem[i] = arr[s2++];
    }

    for (i = left; i <= right; ++i) arr[i] = tem[i];
}

void merge_sort(int arr[], int n)
{
    int *tem = (int *)malloc(n * sizeof(*arr));
    do_merge_sort(arr, tem, 0, n-1);
    free(tem);
}

