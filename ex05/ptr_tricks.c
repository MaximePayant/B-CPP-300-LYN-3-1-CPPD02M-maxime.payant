/*
** EPITECH PROJECT, 2021
** CPP_D02M
** File description:
** ptr_tricks.c
*/

#include "ptr_tricks.h"

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    int result = ptr2 - ptr1;

    result = (result < 0 ? result * -1 : result);
    return (result);
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    const whatever_t test;
    int len = get_array_nb_elem((const int *)(&test), &test.member);

    return ((whatever_t *)(member_ptr - len));
}