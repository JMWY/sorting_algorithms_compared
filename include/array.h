/******************************************************************
  * File Name     : array.h
  * Description   : 
  *
  * Copyright (C) 2016 Yangguang Li
  * Mail          : liyggyj@163.com
  * Author        : Yangguang Li
  * Created time  : 2017-01-19 11:19:57 AM
  * Last modified : 2017-01-19 11:19:57 AM
******************************************************************/
#ifndef __ARRAY_H__
# define __ARRAY_H__

# include <sys/time.h>

# define ARR_SIZE 50000
# define MAX_NUM  1000000

typedef enum sortType {
    TYPE_OF_SORT_HEAP = 0,
    TYPE_OF_SORT_QUICK,
    TYPE_OF_SORT_MERGE,
    TYPE_OF_SORT_INSERT,
    TYPE_OF_SORT_SHELL,
    TYPE_OF_SORT_MAX
} sortType; 

typedef void (*sortFunc) (int *arr, int sz);

typedef struct sortFactory {
    unsigned int flags; // for en(de)register
    struct SortMethod {
        const char *description;
        struct timeval runtime;
        sortFunc sortfunc;
    } methods[TYPE_OF_SORT_MAX];
} sortFactory;

# define do_enregister(sorttype)                \
    do {                                        \
        (factory).flags |= 1 << (sorttype);     \
    } while (0)

# define do_deregister(sorttype)                \
    do {                                        \
        (factory).flags &= ~(1 << (sorttype));  \
    } while (0)

void print_arr();
void set_arr();
void sort_arr();
void enregister(sortType st);
void deregister(sortType st);

# define get_passedtime(pretime)                \
    do {                                        \
        struct timeval cur_time;                \
        gettimeofday(&cur_time, NULL);          \
        (pretime)->tv_sec = cur_time.tv_sec - (pretime)->tv_sec;     \
        (pretime)->tv_usec = cur_time.tv_usec - (pretime)->tv_usec;   \
        if ((pretime)->tv_usec < 0) {           \
            (pretime)->tv_usec += 1*1000*1000;  \
            (pretime)->tv_sec--;                \
        }                                       \
    } while(0)    

# define print_runtime(tv) \
    do {                    \
        printf("[--time passed: %ld s   %-7.3f ms]\n", \
        (tv)->tv_sec, (float)(tv)->tv_usec / 1000); \
    } while (0)
        
    

# define do_sort(sortMethod)                        \
    do {                                            \
        if (NULL == sortMethod.sortfunc) continue;  \
        gettimeofday(&sortMethod.runtime, NULL);    \
        sortMethod.sortfunc(get_arr(), ARR_SIZE);   \
        get_passedtime(&sortMethod.runtime);  \
        printf("%-15s ", sortMethod.description);     \
        print_runtime(&sortMethod.runtime);     \
    } while(0)

#endif
