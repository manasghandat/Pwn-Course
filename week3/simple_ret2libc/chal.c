#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/prctl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <signal.h>

void gadget(){
    __asm__(
        ".intel_syntax noprefix;"
        "pop rdi;"
        "ret;"
        ".att_syntax;"
    );
}

void setup()
{
  setvbuf(stdout,NULL,2,0);
  setvbuf(stderr,NULL,2,0);
  setvbuf(stdin,NULL,2,0);
}

void vuln(){
    char buf[0x20];
    printf(">>");
    gets(buf);
}

int main(int argc, char const *argv[])
{
    setup();
    puts("Well just solve it already");
    vuln();
    return 0;
}