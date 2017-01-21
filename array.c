/******************************************************************
  * File Name     : array.c
  * Description   : 
  *
  * Copyright (C) 2016 Yangguang Li
  * Mail          : liyggyj@163.com
  * Author        : Yangguang Li
  * Created time  : 2017-01-19 11:34:44 AM
  * Last modified : 2017-01-22 12:02:09 AM
******************************************************************/
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# include <sys/time.h>


extern void quick_sort(int *arr, int n);
extern void merge_sort(int *arr, int n);
extern void heap_sort(int *arr, int n);
extern void shell_sort(int *arr, int n);
extern void insert_sort(int *arr, int n);

static sortFactory factory = {
.flags = 0,
.methods = {
    {
        .description = "Heap-Sort",
        .sortfunc = heap_sort,
    },
    {
        .description = "Quick-Sort",
        .sortfunc = quick_sort,
    },
    {
        .description = "Merge-Sort",
        .sortfunc = merge_sort,
    },
    {
        .description = "Insert-Sort",
        .sortfunc = insert_sort,
    },
    {
        .description = "Shell-Sort",
        .sortfunc = shell_sort,
    }}
};

static int *get_arr()
{
    static int arr[ARR_SIZE] = {8};
    return arr;
}

void print_arr(const char *descrip)
{
    int *arr = get_arr();
    int i;
	printf("%s", descrip);
    for (i = 0; i < ARR_SIZE; ++i)
        printf("%d\t", arr[i]);

    printf("\n");
}

void set_arr()
{
    int *arr = get_arr();
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < ARR_SIZE; ++i)
        arr[i] = rand() % MAX_NUM;
}

void sort_arr()
{
    int i = 0;
    unsigned int flags = factory.flags;
    if (!flags) return;

    for (i = 0; i < TYPE_OF_SORT_MAX; i++) {
        if (flags & (1 << i))
            do_sort(factory.methods[i]);
    }
}

void enregister(sortType st)
{
	do_enregister(st);
}

void deregister(sortType st)
{
	do_deregister(st);
}
