/******************************************************************
  * File Name     : heap_sort.c
  * Description   : 构造了大顶堆。大顶堆：能找出最小的k个数；小顶堆: 找出最大的k个数。
  *
  * Copyright (C) 2016 Yangguang Li
  * Mail          : liyggyj@163.com
  * Author        : Yangguang Li
  * Created time  : 2017-01-20 07:35:07 PM
  * Last modified : 2017-01-21 11:15:52 PM
******************************************************************/
/* version 1 */

/*自顶向下调整*/
static void heap_adjust(int heap[], int n, int father)
{
	int val = heap[father];
	int child = (father << 1) + 1;
	while (child < n) {
		if (child +1 < n && heap[child] <= heap[child+1]) ++child;
		if (heap[child] <= val) break; // note the mistake  of 'heap[child] <= heap[father]'
		heap[father] = heap[child];
		father = child;
		child = (father << 1) + 1;
	}
	heap[father] = val;
}

static void heap_pop(int heap[], int n)
{
	if (0 == --n) return; // 位置n删除，放置堆顶元素
	heap[0] ^= heap[n];
	heap[n] ^= heap[0];
	heap[0] ^= heap[n];
	
	heap_adjust(heap, n, 0);

}

static void do_heap_sort(int heap[], int n)
{
	int i;
	for (i = n-1>>1; i >= 0; --i)
		heap_adjust(heap, n, i);
	for (i = 0; i < n; ++i)
		heap_pop(heap, n-i);
}


/**************************************/
/* version 2 */

static int *heap;
static int sz;
static int maxsize;

/*自底向上调整*/
static void push(int val)
{
	int child = sz++;
	while (child > 0) {
		int father = child - 1 >> 1;
		if (val <= heap[father]) break;
		heap[child] = heap[father];
		child = father;
	}
	heap[child] = val;
}

/*调用 heap_adjust 函数做自顶向下调整*/
static int pop()
{
	int val = heap[0];
	heap[0] = heap[--sz];
	heap[sz] = val;
	heap_adjust(heap, sz, 0);
	return val;
}

static void init_heap(int arr[], int n)
{
	heap = arr;
	maxsize = n;
	sz = 0;
}

//#define HEAP_DEBUG
# ifdef HEAP_DEBUG
# include <stdio.h>
static void print_heap()
{
	int i;
	for (i = 0; i < sz; ++i) 
		printf("%d\t", heap[i]);
	printf("\n");
}
#endif

static void do_heap_sort2(int arr[], int n)
{
	int i;
	init_heap(arr, n);

	for (i = 0; i < n; ++i) {
		push(arr[i]);
# ifdef HEAP_DEBUG
		print_heap();
# endif
	}
	for (i = 0; i < n; ++i) {
		pop();
# ifdef HEAP_DEBUG
		print_heap();
# endif
	}
}

/***************************************/

static unsigned flags = 0;

void heap_sort(int heap[], int n)
{
	if (flags)
		do_heap_sort(heap, n);
	else
		do_heap_sort2(heap, n);
}
