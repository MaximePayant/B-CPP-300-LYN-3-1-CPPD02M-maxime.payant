/*
** ShipWreck engine, 2020
** tab_to_2dtab.c
*/

#include <stdlib.h>

void  tab_to_2dtab(const  int *tab , int  length , int width , int  ***res)
{
    *res = malloc(sizeof(int *) * length);
    int tab_ctr = 0;

    for (int lengh_ctr = 0; lengh_ctr < length; lengh_ctr += 1) {
        (*res)[lengh_ctr] = malloc(sizeof(int) * width);
        for (int width_ctr = 0; width_ctr < width; width_ctr += 1) {
            (*res)[lengh_ctr][width_ctr] = tab[tab_ctr];
            tab_ctr += 1;
        }
    }
}