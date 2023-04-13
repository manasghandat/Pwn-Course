#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


__attribute__((constructor))
void setup(){
  setvbuf(stdout,NULL,2,0);
  setvbuf(stderr,NULL,2,0);
  setvbuf(stdin,NULL,2,0);
}

void win(){
    printf("You are goddam right\n");
    system("/bin/sh");
}

void vuln(){
    char buf[0x40] = {0};
    printf("Say my name\n");
    gets(buf);
}

int main(int argc, char const *argv[])
{
    vuln();
    return 0;
}
