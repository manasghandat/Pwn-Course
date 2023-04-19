#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void win(){
    execl("/bin/sh",0,0);
}

void vuln(){
    char buf[0x40] = {0};
    printf("Try to exploit this one now\n");
    gets(buf);
    printf(buf);
}

__attribute__((constructor))
void setup(){
  setvbuf(stdout,NULL,2,0);
  setvbuf(stderr,NULL,2,0);
  setvbuf(stdin,NULL,2,0);
}


int main(int argc, char const *argv[])
{
    vuln();
    return 0;
}
