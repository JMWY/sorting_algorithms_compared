/******************************************************************
  * File Name     : qsort.h
  * Description   : 
  *
  * Copyright (C) 2016 Yangguang Li
  * Mail          : liyggyj@163.com
  * Author        : Yangguang Li
  * Created time  : 2017-01-18 08:59:28 PM
  * Last modified : 2017-01-20 10:12:09 PM
******************************************************************/

static void do_quick_sort(int arr[], int left, int right)
{
	if (left >= right) return;

	int tmpLeft = left,
		tmpRight = right,
		pivot = arr[tmpLeft];

	while (tmpLeft < tmpRight) {
		while (tmpLeft < tmpRight && arr[tmpRight] >= pivot) --tmpRight;
			arr[tmpLeft] = arr[tmpRight];
		while (tmpLeft < tmpRight && arr[tmpLeft] <= pivot) ++tmpLeft;
			arr[tmpRight] = arr[tmpLeft];
	}
	arr[tmpLeft] = pivot;
	
	do_quick_sort(arr, left, tmpLeft);
	do_quick_sort(arr, tmpLeft+1, right);
}


void quick_sort(int arr[], int n)
{
	do_quick_sort(arr, 0, n-1);
}

