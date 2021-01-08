/*
** EPITECH PROJECT, 2021
** CPP_D02M
** File description:
** castmania.c
*/

#include <stdio.h>

#include "castmania.h"

void exec_operation(instruction_type_t instruction_type, void *data)
{
    instruction_t *instruction = (instruction_t *)data;

    if (instruction_type == ADD_OPERATION) {
        exec_add((addition_t *)instruction->operation);
        if (instruction->output_type == VERBOSE)
            printf("%i\n", ((addition_t *)
            instruction->operation)->add_op.res);
    } else if (instruction_type == DIV_OPERATION) {
        exec_div((division_t *)instruction->operation);
        if (instruction->output_type == VERBOSE) {
            if (((division_t *)instruction->operation)->div_type == INTEGER)
                printf("%i\n", ((integer_op_t *)
                ((division_t *)instruction->operation)->div_op)->res);
            else
                printf("%f\n", ((decimale_op_t *)
                ((division_t *)instruction->operation)->div_op)->res);
        }
    }
}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
    switch (instruction_type)
    {
        case PRINT_INT:
            printf("%i\n", *(int *)data);
            break;
        case PRINT_FLOAT:
            printf("%f\n", *(float *){data});
            break;
        default:
            exec_operation(instruction_type, data);
            break;
    }
}