#include <fcntl.h>
#include <seccomp.h>
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

char flag[0x100];

void setup()
{
  setvbuf(stdout,NULL,2,0);
  setvbuf(stderr,NULL,2,0);
  setvbuf(stdin,NULL,2,0);
}

void seccomp_filter() {
  scmp_filter_ctx ctx;
  ctx = seccomp_init(SCMP_ACT_ALLOW);
  if (ctx == NULL) {
    exit(0);
  }
  seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(execve), 0);
  seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(execveat), 0);

  seccomp_load(ctx);
}

void vuln(){
    char buf[0x20];
    printf(">>");
    gets(buf);
}

int main(int argc, char const *argv[])
{
    setup();
    puts("Are you ready for a tough challenge?");
    int fd = open("./flag",O_RDONLY);
    read(fd,flag,sizeof(flag));
    close(fd);
    seccomp_filter();
    vuln();
    return 0;
}