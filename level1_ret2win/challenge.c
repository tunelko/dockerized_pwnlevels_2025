
#include <stdio.h>
#include <stdlib.h>

void win() {
    puts(">> Has entrado en win()");
    FILE *f = fopen("flag.txt", "r");
    if (f) {
        char buf[128];
        if (fgets(buf, sizeof(buf), f) != NULL) {
            puts(buf);  // imprime la flag con salto de línea
            fflush(stdout);
        }
        fclose(f);
    } else {
        puts("[!] No se pudo abrir flag.txt");
    }
    sleep(1);
    exit(0);
}

/*void win() {
    
    system("cat flag.txt");
    fflush(stdout);  // Fuerza a volcar el output al terminal
    sleep(1);        // Da tiempo a que llegue a la shell
    exit(0);         // No hagas ret, termina limpio
}
*/

void vuln() {
    char buf[64];
    puts("Welcome to Level 1: ret2win");
    gets(buf);
}

int main() {
    setbuf(stdout, NULL);
    vuln();
    return 0;
}
