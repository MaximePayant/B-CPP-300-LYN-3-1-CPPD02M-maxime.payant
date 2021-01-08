/*
** EPITECH PROJECT, 2021
** CPP_D02M
** add.c
*/

#include "castmania.h"

int normal_add(int a, int b)
{
    return (a + b);
}

int absolute_add(int a, int b)
{
    a = (a < 0 ? a * -1 : a);
    b = (b < 0 ? b * -1 : b);
    return (a + b);
}

void exec_add(addition_t *operation)
{
    int (*func[2])(int a, int b) = {normal_add, absolute_add};

    operation->add_op.res =
    func[operation->add_type](operation->add_op.a, operation->add_op.b);
}