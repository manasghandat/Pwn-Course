#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char buf[0x40] = {0};
int kek ;

void setup(){
    setvbuf(stdout,NULL,2,0);
    setvbuf(stderr,NULL,2,0);
    setvbuf(stdin,NULL,2,0);
}

void vuln(){
    printf("Please enter name\n");
    gets(buf);
    if(kek==0x1337){
        int fd = open("flag",O_RDWR);
        read(fd,buf,sizeof(buf));
        printf("%s",buf);
    }
}

int main(int argc, char const *argv[])
{
    setup();
    vuln();
    return 0;
}
