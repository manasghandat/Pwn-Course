#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


__attribute__((constructor))
void setup(){
  setvbuf(stdout,NULL,2,0);
  setvbuf(stderr,NULL,2,0);
  setvbuf(stdin,NULL,2,0);
}


void __gadgets(){
    __asm__(
        ".intel_syntax noprefix;"
        "pop rsi;"
        "pop rax;"
        "ret;"
        ".att_syntax;"
    );

    __asm__(
        ".intel_syntax noprefix;"
        "pop rdi;"
        "ret;"
        ".att_syntax;"
    );

    __asm__(
        ".intel_syntax noprefix;"
        "pop rbp;"
        "pop r9;"
        "pop r8;"
        "mov rcx, r8;"
        "pop rdx;"
        "ret;"
        ".att_syntax;"
    );
}

void win(long a, long b, long c,long d){
    if(a == 0xdeadbeef && d == 0xcafebabe && b == 0xdeaddead && c == 0xcafecafe){
        printf("You won\n");
        system("/bin/sh");
    }
    else{
        printf("Kek\n");
    }
}

void vuln(){
    char buf[0x40] = {0};
    printf("Overflow here:\n");
    gets(buf);
}

int main(int argc, char const *argv[])
{
    vuln();
    return 0;
}
