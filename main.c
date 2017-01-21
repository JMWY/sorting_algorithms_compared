/******************************************************************
  * File Name     : sort.c
  * Description   : 
  *
  * Copyright (C) 2016 Yangguang Li
  * Mail          : liyggyj@163.com
  * Author        : Yangguang Li
  * Created time  : 2017-01-18 09:17:38 PM
  * Last modified : 2017-01-21 11:25:04 PM
******************************************************************/
#include <stdio.h>
#include "array.h"

int main()
{
    set_arr();
    //print_arr("Before sort: ");
    enregister(TYPE_OF_SORT_MERGE);
    sort_arr();
    //print_arr("After  sort: "); putchar('\n');
    deregister(TYPE_OF_SORT_MERGE);

    //sleep(1);

    set_arr();
    //print_arr("Before sort: ");
    enregister(TYPE_OF_SORT_HEAP);
    sort_arr();
    //print_arr("After  sort: "); putchar('\n');
    deregister(TYPE_OF_SORT_HEAP);

    //sleep(1);

    set_arr();
    //print_arr("Before sort: ");
    enregister(TYPE_OF_SORT_QUICK);
    sort_arr();
    //print_arr("After  sort: "); putchar('\n');
    deregister(TYPE_OF_SORT_QUICK);

    //sleep(1);

    set_arr();
    //print_arr("Before sort: ");
    enregister(TYPE_OF_SORT_SHELL);
    sort_arr();
    //print_arr("After  sort: "); putchar('\n');
    deregister(TYPE_OF_SORT_SHELL);

    //sleep(1);

    set_arr();
    //print_arr("Before sort: ");
    enregister(TYPE_OF_SORT_INSERT);
    sort_arr();
    //print_arr("After  sort: "); putchar('\n');
    deregister(TYPE_OF_SORT_INSERT);

}
