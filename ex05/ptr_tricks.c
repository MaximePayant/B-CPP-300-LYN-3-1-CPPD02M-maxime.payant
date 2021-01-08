/*
** ShipWreck engine, 2020
** ptr_tricks.c
*/

#include "ptr_tricks.h"

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    int len = 0;

    while (ptr1 + len != ptr2)
        len += 1;
    len = (len < 0 ? len * -1 : len);
    return (len);
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    const whatever_t test;
    int len = get_array_nb_elem((const int *)(&test), &test.member);

    return ((whatever_t *)(member_ptr - len));
}