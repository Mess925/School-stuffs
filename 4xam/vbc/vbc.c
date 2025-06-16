#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

const char *s;

void error(char c) {
    write(2, "unexpected token '", 18);
    write(2, &c, 1);
    write(2, "'\n", 2);
    exit(1);
}

int expr(); // forward

int number() {
    if (*s >= '0' && *s <= '9')
        return( *s++ - '0');
    else if (*s == '(') {
        s++;
        int val = expr();
        if (*s != ')')
            error(*s);
        s++;
        return val;
    }
    error(*s);
    return 0;
}

int term() {
    int val = number();
    while (*s == '*') {
        s++;
        val *= number();
    }
    return val;
}

int expr() {
    int val = term();
    while (*s == '+') {
        s++;
        val += term();
    }
    return val;
}

int main(int ac, char **av) {
    if (ac != 2)
        return 1;
    s = av[1];
    int result = expr();
    if (*s)
        error(*s);
    printf("%d\n", result);
    return 0;
}
