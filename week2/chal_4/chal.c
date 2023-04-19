#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


__attribute__((constructor))
void setup(){
  setvbuf(stdout,NULL,2,0);
  setvbuf(stderr,NULL,2,0);
  setvbuf(stdin,NULL,2,0);
}

void __gadget(){
    __asm__(
        ".intel_syntax noprefix;"
        "pop rdi;"
        "pop rax;"
        "ret;"
        ".att_syntax;"
    );

}

void win(long a){
    if(a == 0xdeadbeef){
        system("/bin/sh");
    }
}

void vuln(){
    char buf[0x40] = {0};
    printf("Whats your name\n");
    read(0,buf,0x100);
    puts(buf);
    gets(buf);
}

int main(int argc, char const *argv[])
{
    vuln();
    return 0;
}
