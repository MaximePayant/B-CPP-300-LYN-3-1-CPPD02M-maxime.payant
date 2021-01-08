/*
** EPITECH PROJECT, 2021
** CPP_D02M
** mem_ptr.c
*/

#include <stdlib.h>
#include "mem_ptr.h"

int string_len(const char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len += 1;
    return (len);
}

void add_str(const char *str1, const char *str2, char **res)
{
    int total_len = string_len(str1) + string_len(str2);
    int res_ctr = 0;

    *res = malloc(sizeof(char) * (total_len + 1));
    for (int ctr = 0; str1[ctr] != '\0'; ctr += 1) {
        (*res)[res_ctr] = str1[ctr];
        res_ctr += 1;
    }
    for (int ctr = 0; str2[ctr] != '\0'; ctr += 1) {
        (*res)[res_ctr] = str2[ctr];
        res_ctr += 1;
    }
    (*res)[total_len] = '\0';
}

void add_str_struct(str_op_t *str_op)
{
    add_str(str_op->str1, str_op->str2, &str_op->res);
}