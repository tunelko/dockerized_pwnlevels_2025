
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void vuln() {
    char buf[64];
    puts("Welcome to Level 3: ret2libc");
    printf("puts@got: %p\n", puts);
    gets(buf);
}

int main() {
    setbuf(stdout, NULL);
    vuln();
    return 0;
}
