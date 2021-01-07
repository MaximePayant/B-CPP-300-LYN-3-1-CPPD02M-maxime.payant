/*
** ShipWreck engine, 2020
** func_ptr.c
*/

#include "func_ptr.h"
#include <unistd.h>

void print_normal(const  char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len += 1;
    write(1, str, len);
    write(1, "\n", 1);
}

void print_reverse(const  char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len += 1;
    while (len > 0) {
        len -= 1;
        write(1, &str[len], 1);
    }
    write(1, "\n", 1);
}

void print_upper(const  char *str)
{
    int len = 0;
    char c = 0;

    while (str[len] != '\0') {
        if ('a' <= str[len] && str[len] <= 'z')
            c = str[len] - 32;
        else
            c = str[len];
        write(1, &c, 1);
        len += 1;
    }
    write(1, "\n", 1);
}

void  print_42(const  char *str)
{
    (void)str;
    write(1, "42\n", 3);
}

void do_action(action_t action , const  char *str)
{
    void (*func[4])(const char *ptr);

    func[PRINT_NORMAL] = *print_normal;
    func[PRINT_REVERSE] = *print_reverse;
    func[PRINT_UPPER] = *print_upper;
    func[PRINT_42] = *print_42;
    func[action](str);
}