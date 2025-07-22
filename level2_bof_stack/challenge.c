
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void shell() {
    system("/bin/sh");
}

void vuln() {
    char buf[128];
    puts("Welcome to Level 2: bof_stack");
    read(0, buf, 256);
}

int main() {
    setbuf(stdout, NULL);
    vuln();
    return 0;
}
