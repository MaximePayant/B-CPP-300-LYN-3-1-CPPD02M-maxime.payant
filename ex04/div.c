/*
** ShipWreck engine, 2020
** div.c
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    if (b == 0)
        return (0);
    return (a / b);
}

float decimale_div(int a, int b)
{
    if (b == 0)
        return (0);
    return (a / b);
}

void exec_div(division_t *operation)
{
    int (*func[2])(int a, int b) = {integer_div, decimale_div};

    if (operation->div_type == INTEGER)
        ((integer_op_t *)operation->div_op)->res =
        func[operation->div_type](((integer_op_t *)operation->div_op)->a
        , ((integer_op_t *)operation->div_op)->b);
    else
        ((decimale_op_t *)operation->div_op)->res =
        func[operation->div_type](((decimale_op_t *)operation->div_op)->a
        , ((decimale_op_t *)operation->div_op)->b);
}